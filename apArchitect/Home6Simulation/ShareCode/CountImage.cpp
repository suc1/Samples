#include <iostream>

#include "CountImage.h"
#include "Camera.h"

using namespace std;

CountImage::CountImage() {	
}

void CountImage::Subscribe(Camera* pCamera) {
	pCamera->Subscribe(std::bind(&CountImage::ProcessImage, this, std::placeholders::_1));
}

void CountImage::Subscribe(CountImage::CALLBACK callback) {
	m_callback.push_back( callback );
}

void CountImage::ProcessImage(IMAGE img) {
	for (auto i : m_img) {
		if (img == i) return;
	}

	m_img.push_back(img);

	int len = (int)m_img.size();
	//cout << "CountImage::ProcessImage = " << len << endl;
	for (auto cb : m_callback) {
		cb(len);
	}
}

