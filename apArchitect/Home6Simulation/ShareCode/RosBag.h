#pragma once
#include <fstream>
#include <functional>

#include "Image.h"

/// <summary>
/// .bag文件格式: TXT, 每个消息一行(类型，数据). For example:
/// 0, 11	//CAT相机,  图象内容是11
/// 1, 20	//DOG相机,  图象内容是20
/// 2, 8    //CAT计数, 8个
/// 3, 6    //DOG计数, 6个
/// </summary>
class RosBag
{
public:
	enum MessageType {CAT, DOG, COUNT_CAT, COUNT_DOG};
public:
	RosBag(bool record = true); //Record/Play
	~RosBag();
	
	void Play( std::function< void(const char*) > rec);
	void Process(int type, int count);
	void ProcessImage(int type, IMAGE img);

private:
	std::fstream m_file;
};

