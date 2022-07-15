//
//  client.cc
//
//  Copyright (c) 2019 Yuji Hirose. All rights reserved.
//  MIT License
//

#include <iostream>

#include "../../../ThirdPartyLib/cpp-httplib/httplib.h"

#include "BigFile.h"
#include "BigFileClient.h"

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

    cli.set_keep_alive(true);
    cli.set_connection_timeout(100);

    BigFileClient bg(cli);
    auto res = bg.CheckFileStatus( R"(D:\sample\apArchitect\home3dataCollectStore\Client\Client.cpp)" );
    if (res == nullptr) return -1;
    if(res->status!=200) return -1;

    int pos = stoi( res->body );
    if (pos < 0) {
        //秒传
        cout << "File has been transfered before" << endl;
        return 0;
    }

    //ToDo: reuse MultipartFormData???
    while (pos >= 0) {
        cli.set_keep_alive(true);	//Why need repeat line 35-36??
        cli.set_connection_timeout(100);

        res = bg.SendChunk(pos);
        if (res == nullptr) return -1;
        if (res->status != 200) return -1;

        pos = stoi(res->body);
    }

    return 0;
}
