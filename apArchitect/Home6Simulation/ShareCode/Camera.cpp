#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <random>
#include <functional>

#include "Camera.h"

using namespace std;

static const int FPS = 10;
static const int MAX_IMAGE_NO = 10000;

static std::uniform_int_distribution<int> dice_distribution(0, MAX_IMAGE_NO);
static std::mt19937					   random_number_engine; // pseudorandom number generator
static auto dice_roller = std::bind(dice_distribution, random_number_engine);

Camera::Camera() {
	//srand((unsigned int)time(NULL));		//两个线程随机数一样，所以必须放到主线程里	//即使对rand()加锁，还是一样 //最后使用dice_roller
}

Camera::~Camera() {
	SetExitFlag();
	if(m_thread.joinable()) m_thread.join();
}

void Camera::Start() {
	cout << "Camera::Start()" << endl;

	m_thread = std::thread(&Camera::Advertise, this);
}

void Camera::Subscribe(Camera::CALLBACK callback) {
	std::lock_guard<std::mutex> lock(m_mutex);
	m_callback.push_back( callback );
}

void Camera::SetCurrentImage(IMAGE img) {
	if (m_img == img) return;

	std::vector<Camera::CALLBACK> callback;
	{
		std::lock_guard<std::mutex> lock(m_mutex);
		m_img = img;
		callback = m_callback;
	}
	
	for (auto cb : callback)
	{
		cb(img);
	}
}

void Camera::Advertise() {
	while(!m_exit) {
		std::this_thread::sleep_for( std::chrono::milliseconds(1000/FPS) );
		int img;
		/*
		{
			std::lock_guard<std::mutex> lock(m_mutex);	//两个线程随机数一样, 即使对rand()加锁
			img = rand() % MAX_IMAGE_NO;
		} */
		img = dice_roller();
		//cout << "Camera::Advertise() = " << img << endl;
		SetCurrentImage(img);
	}
}