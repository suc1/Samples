//See README.md for details
#pragma once

#include <vector>
#include <functional>

#include "Image.h"

class Camera;
class CountImage
{
public:
	typedef std::function< void(int) > CALLBACK;

public:
	CountImage();
	~CountImage() = default;

	void Subscribe(Camera* pCamera);
	void Subscribe(CALLBACK callback);	//监测到了多少小猫小狗
	
	void Debug();

private:
	void ProcessImage(IMAGE img);

private:
	std::vector<IMAGE> m_img;
	std::vector<CALLBACK> m_callback;
};

