#pragma once
/**
 * 大文件的读写
 *
 *
 * 支持: 分片读写
 * ToDo: multiple connections/threads, 复用文件句柄
 *
 */
 //50G = 50 * 1024 * 1024 *1024 = 536 8709 1200 = C8000 0000 = 5 byte = int64_t
#include <string>
#include <memory>
#include <fstream>

class BigFile {
public:
	const int m_chunkSize = 16; //分片长度, 2^31 = 2,147,483,648
public:
	BigFile(const char* fileName, bool forRead);	//Client=Read, Server=Write
	~BigFile();

	///Client=Read
	//https://github.com/stbrumme/hash-library
	std::string HashFileContent();
	std::unique_ptr<char> ReadChunk(int chunkNo);

	///Server=Write
	bool WriteChunk(const std::string& fileHash, int chunkNo);
public:
	std::string m_fileName;
	struct stat m_stat;
private:
	std::fstream m_file;
};