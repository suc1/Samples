#include "Camera.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

static const int FPS = 1;
static const int MAX_IMAGE_NO = 10000;

Camera::Camera() {
}

Camera::~Camera() {
	SetExitFlag();
	m_thread.join();
}

void Camera::Start() {
	cout << "Camera::Start()" << endl;

	srand((unsigned int)time(NULL));
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
		cb(m_img);
	}
}

void Camera::Advertise() {
	while(!m_exit) {
		std::this_thread::sleep_for( std::chrono::milliseconds(1000/FPS) );
		int img = rand() % MAX_IMAGE_NO;
		//cout << "Camera::Advertise() = " << img << endl;
		SetCurrentImage(img);
	}
}