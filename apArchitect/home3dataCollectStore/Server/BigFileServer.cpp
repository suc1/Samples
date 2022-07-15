#include "../../../ThirdPartyLib/cpp-httplib/httplib.h"

#include "ControlFile.h"
#include "BigFile.h"
#include "BigFileServer.h"

using namespace std;

void BigFileServer::checkFileStatus(const httplib::Request& req, httplib::Response& res) {
    //ToDo: Only support 1 file
    if (m_pConf != nullptr) m_pConf->ExitInstance();
    if (m_pBigFile != nullptr) delete m_pBigFile;

    std::string hashFile = req.get_param_value("hash");
    int length = stoi( req.get_param_value("length") );
    int chunkSize = stoi( req.get_param_value("chunkSize") );

    m_pConf = ControlFile::Instance(hashFile, length, chunkSize);
    int pos = m_pConf->StartPoint(hashFile);
    //秒传
    //断点续传
    res.set_header("StartPoint", to_string(pos));
    res.set_content("BigFile", "text/html");

    if (pos >= 0) {
        m_pBigFile = new BigFile(hashFile.c_str(), false);
    }
}

bool BigFileServer::ReceiveChunk(const httplib::Request& req, httplib::Response& res) {

    return false;
}