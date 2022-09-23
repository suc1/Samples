#pragma once
/**
 * Client端处理大文件的读写
 *
 *
 * 支持: 分片读写
 * ToDo: multiple files. Now only support 1 file
 *
 */
#include <string>

namespace httplib {
	struct Request;
	struct Response;
	class  Result;
}

class BigFile;
class BigFileClient {
public:
	BigFileClient(httplib::Client& cli) : m_cli(cli) {}
	~BigFileClient() = default;

	httplib::Result CheckFileStatus(const char* fileName);
	httplib::Result SendChunk(int no);

private:
	BigFile* m_pBigFile = nullptr;
	httplib::Client &m_cli;
};
