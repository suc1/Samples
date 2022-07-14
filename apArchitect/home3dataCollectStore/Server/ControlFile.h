#pragma once

#include <string>

/**
 * 服务器端对大文件的控制文件
 *
 * 
 * 支持: 秒传, 断点续传
 * ToDo: support many files, multiple connections/threads, 复用文件句柄
 * 
 */
//50G = 50 * 1024 * 1024 *1024 = 536 8709 1200 = C8000 0000 = 5 byte = int64_t
class ControlFile {
public:
#pragma pack (push, 1)
	struct RECORD{
		uint64_t    length;		//总长度
		uint32_t	chunkSize;	//分片长度
		uint32_t	chunkSum;	//多少分片
		bool		flag[1];	//true上传完毕
	} *m_pRec;
#pragma pack (pop)

private:
	static ControlFile* m_pInst;

private:
	ControlFile(const std::string& fileHash, uint64_t length, uint32_t	chunkSize);
	~ControlFile();
	bool SaveChunk(const std::string& fileHash);
	static inline std::string FileName(const std::string& fileHash) {
		std::string fileName(fileHash + ".conf");
		return fileName;
	}

public:
	static ControlFile* Instance(const std::string& fileHash, uint64_t length=0, uint32_t	chunkSize=0);
	int StartPoint(const std::string& fileHash);
	bool SaveChunk(const std::string& fileHash, int no);
};
