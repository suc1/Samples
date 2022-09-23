//See README.md for details
#pragma once

#include <functional>
#include <vector>
#include <mutex>
#include <thread>

#include "Image.h"

class Camera
{
public:
	typedef std::function< void(IMAGE) > CALLBACK;

public:
	Camera();
	~Camera();

	void Subscribe( CALLBACK callback );	//接收摄像头图象
	void Start();	//Start camera thread
	void SetExitFlag() { m_exit = true; }
	
	//仿真
	void SetCurrentImage(IMAGE img);

private:
	void Advertise();

private:
	IMAGE m_img;
	std::vector<CALLBACK> m_callback;
	std::mutex m_mutex;
	bool m_exit = false;
	std::thread m_thread;
};
