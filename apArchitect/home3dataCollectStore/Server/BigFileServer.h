#pragma once
/**
 * 服务器端处理大文件的读写
 *
 *
 * 支持: 分片读写
 * ToDo: multiple files. Now only support 1 file
 *
 */

#include <memory>

namespace httplib {
	struct Request;
	struct Response;
}
class ControlFile;
class BigFile;
class BigFileServer {
public:
	BigFileServer() = default;
	~BigFileServer() = default;
	
	void Post(const httplib::Request& req, httplib::Response& res);

private:
	void CheckFileStatus(const std::string& fileHash, uint64_t length, uint32_t	chunkSize, httplib::Response& res);
	bool ReceiveChunk(const std::string& hashFile, const char* content, int no, int length, httplib::Response& res);
private:
	ControlFile  *m_pConf    = nullptr;
	BigFile      *m_pBigFile = nullptr;
};