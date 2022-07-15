#include "../../../ThirdPartyLib/cpp-httplib/httplib.h"

#include "BigFileClient.h"
#include "BigFile.h"

using namespace std;

httplib::Result BigFileClient::CheckFileStatus(const char* fileName) {
    if (m_pBigFile != nullptr) delete m_pBigFile;

    m_pBigFile = new BigFile(fileName, true);
    string hashParam = m_pBigFile->HashFileContent();
    httplib::Headers headers = { 
        {"method",      "enquiry"},
        {"hash",        hashParam},
        {"length",      to_string(m_pBigFile->m_stat.st_size)},
        {"chunkSize",   to_string(m_pBigFile->m_chunkSize)},
    };
    httplib::Params items = {
        //{ "method",     "enquiry"},
        //{ "hash",       hashParam},
        //{ "length",     to_string(m_pBigFile->m_stat.st_size)},
        //{ "chunkSize",  to_string(m_pBigFile->m_chunkSize)},
    };
    
    return m_cli.Post("/BigFile", headers, items);
}

httplib::Result BigFileClient::SendChunk(int no) {
    int len;
    std::unique_ptr<char> chunk = m_pBigFile->ReadChunk(no, len);
    string hashParam = m_pBigFile->HashFileContent();
    httplib::Headers headers = {
        {"method",      "upload"},
        {"hash",        hashParam},
        {"no",          to_string(no)},
        {"length",      to_string(len)},
        //ToDo: CRC
    };
 
    return m_cli.Post("/BigFile", headers, chunk.get(), len, "application/octet-stream");
}