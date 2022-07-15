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

	void checkFileStatus(const httplib::Request& req, httplib::Response& res);
	bool ReceiveChunk(const httplib::Request& req, httplib::Response& res);
private:
	ControlFile  *m_pConf    = nullptr;
	BigFile      *m_pBigFile = nullptr;
};