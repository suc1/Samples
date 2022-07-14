//
//  client.cc
//
//  Copyright (c) 2019 Yuji Hirose. All rights reserved.
//  MIT License
//

#include <iostream>
#include "D:/study/cpp-httplib/httplib.h"
//https://github.com/yhirose/cpp-httplib.git

#ifdef CPPHTTPLIB_OPENSSL_SUPPORT
#undef CPPHTTPLIB_OPENSSL_SUPPORT
#endif


#define CA_CERT_FILE "./ca-bundle.crt"

using namespace std;

string GetFileHash(const string& fileName) {
    return "123abc";
}

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

    //ToDo: "/BigFile?" + GetFileHash("1.data")
    string checkFileStatus = "/BigFile?hash=" + GetFileHash("1.data");
    auto res = cli.Get(checkFileStatus.c_str());
    if (res == nullptr) return -1;

    cout << res->status << endl;
    cout << res->get_header_value("Content-Type") << endl;
    cout << res->body << endl;

    return 0;
}
