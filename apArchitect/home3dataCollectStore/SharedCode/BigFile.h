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
	const static int m_chunkSize = 1024; //分片长度, 2^31 = 2,147,483,648
public:
	BigFile(const char* fileName, bool forRead);	//Client=Read, Server=Write
	~BigFile();

	///Client=Read
	//https://github.com/stbrumme/hash-library
	std::string HashFileContent();
	std::unique_ptr<char> ReadChunk(int chunkNo, int &len);

	///Server=Write
	bool WriteChunk(const char* content, int chunkNo, int len);
public:
	std::string m_fileName;
	std::string m_hashFile;
	struct stat m_stat;

private:
	inline int GetReadWriteLen(int pos, int maxLen = m_chunkSize) const {
		int readLen = m_stat.st_size - pos;
		if (readLen > maxLen) readLen = maxLen;
		return readLen;
	}
private:
	std::fstream m_file;
};