//
//  client.cc
//
//  Copyright (c) 2019 Yuji Hirose. All rights reserved.
//  MIT License
//

#include <iostream>

#include "D:/study/cpp-httplib/httplib.h"
//https://github.com/yhirose/cpp-httplib.git

#include "BigFile.h"

#ifdef CPPHTTPLIB_OPENSSL_SUPPORT
#undef CPPHTTPLIB_OPENSSL_SUPPORT
#endif


#define CA_CERT_FILE "./ca-bundle.crt"

using namespace std;

int main(void) {
#ifdef CPPHTTPLIB_OPENSSL_SUPPORT
    httplib::SSLClient cli("localhost", 8080);
    //httplib::SSLClient cli("google.com");
    //httplib::SSLClient cli("www.youtube.com");
    cli.set_ca_cert_path(CA_CERT_FILE);
    cli.enable_server_certificate_verification(true);
#else
    httplib::Client cli("localhost", 8080);
#endif

    //cli.set_keep_alive(true);
    //cli.set_connection_timeout(100);

    BigFile bg(R"(D:\sample\apArchitect\home3dataCollectStore\Client\Client.cpp)", true);
    string hashParam = bg.HashFileContent();
    hashParam = httplib::detail::encode_query_param(hashParam);
    char buf[512];
    snprintf(buf, sizeof(buf), "/BigFile?hash=%s&length=%d&chunkSize=%d", hashParam.c_str(), bg.m_stat.st_size, bg.m_chunkSize);
     auto res = cli.Get(buf);
    if (res == nullptr) return -1;
    if(res->status!=200) return -1;

    //httplib::Headers headers = { {"StartPoint", "345"} };
    //int pos = res->get_header_value<int>(headers, "StartPoint");
    //cout << "pos=" << pos << endl;


    cout << res->status << endl;
    cout << res->get_header_value("StartPoint") << endl;
    cout << res->body << endl;

    return 0;
}
