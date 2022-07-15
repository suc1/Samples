#include "../../../ThirdPartyLib/cpp-httplib/httplib.h"

#include "ControlFile.h"
#include "BigFile.h"
#include "BigFileServer.h"

using namespace std;

void BigFileServer::Post(const httplib::Request& req, httplib::Response& res) {
    std::string method = req.get_header_value("method");
    if (method == "enquiry") {
        std::string hashFile = req.get_header_value("hash");
        int length = stoi(req.get_header_value("length"));
        int chunkSize = stoi(req.get_header_value("chunkSize"));

        CheckFileStatus(hashFile, length, chunkSize, res);
    }
    else if (method == "upload") {
        std::string hashFile = req.get_header_value("hash");
        int no = stoi(req.get_header_value("no"));
        int length = stoi(req.get_header_value("length"));
        string content = req.body;

        ReceiveChunk(hashFile, content.c_str(), no, length, res);
    }
}

void BigFileServer::CheckFileStatus(const std::string& hashFile, uint64_t length, uint32_t	chunkSize, httplib::Response& res) {
    //ToDo: Only support 1 file
    if (m_pConf != nullptr) m_pConf->ExitInstance();
    if (m_pBigFile != nullptr) delete m_pBigFile;

    m_pConf = ControlFile::Instance(hashFile, length, chunkSize);
    int pos = m_pConf->StartPoint(hashFile);
    //秒传
    //断点续传
    res.set_content(to_string(pos), "text/html");

    if (pos >= 0) {
        m_pBigFile = new BigFile(hashFile.c_str(), false);
    }
}

bool BigFileServer::ReceiveChunk(const string &hashFile, const char* content, int no, int length, httplib::Response& res) {
    //ToDo: CRC
    if (m_pBigFile->WriteChunk(content, no, length)) {
        no += 1;
        if (no >= (int)m_pConf->m_pRec->chunkSum) {
            delete m_pBigFile;
            m_pBigFile = nullptr;
            no = -1;      //finished
        }
        res.set_content(to_string(no), "text/html");
        return true;
    }

    res.set_content(to_string(no), "text/html");    //retry
    return false;
}