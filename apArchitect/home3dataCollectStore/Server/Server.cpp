//
//  sample.cc
//
//  Copyright (c) 2019 Yuji Hirose. All rights reserved.
//  MIT License
//

#include <chrono>
#include <cstdio>
#include <iostream>
#include <fstream>

#include "D:/study/cpp-httplib/httplib.h"
//https://github.com/yhirose/cpp-httplib.git

#ifdef CPPHTTPLIB_OPENSSL_SUPPORT
#undef CPPHTTPLIB_OPENSSL_SUPPORT
#endif

#define SERVER_CERT_FILE "./cert.pem"
#define SERVER_PRIVATE_KEY_FILE "./key.pem"

using namespace std;
using namespace httplib;

std::string dump_headers(const Headers &headers) {
    std::string s;
    char buf[BUFSIZ];

    for (auto it = headers.begin(); it != headers.end(); ++it) {
        const auto &x = *it;
        snprintf(buf, sizeof(buf), "%s: %s\n", x.first.c_str(), x.second.c_str());
        s += buf;
    }

    return s;
}

std::string log(const Request &req, const Response &res) {
    std::string s;
    char buf[BUFSIZ];

    s += "================================\n";

    snprintf(buf, sizeof(buf), "%s %s %s", req.method.c_str(),
           req.version.c_str(), req.path.c_str());
    s += buf;

    std::string query;
    for (auto it = req.params.begin(); it != req.params.end(); ++it) {
        const auto &x = *it;
        snprintf(buf, sizeof(buf), "%c%s=%s",
             (it == req.params.begin()) ? '?' : '&', x.first.c_str(),
             x.second.c_str());
        query += buf;
    }
    snprintf(buf, sizeof(buf), "%s\n", query.c_str());
    s += buf;

    s += dump_headers(req.headers);

    s += "--------------------------------\n";

    snprintf(buf, sizeof(buf), "%d %s\n", res.status, res.version.c_str());
    s += buf;
    s += dump_headers(res.headers);
    s += "\n";

    if (!res.body.empty()) { s += res.body; }

    s += "\n";

    return s;
}

void checkFileStatus(const Request& req, Response& res) {
    std::string hashFileName = req.get_param_value("hash");
    //秒传
    //断点续传
    //res.set_content("id=" + "abc", "text/plain");
}

int main(void) {
#ifdef CPPHTTPLIB_OPENSSL_SUPPORT
    SSLServer svr(SERVER_CERT_FILE, SERVER_PRIVATE_KEY_FILE);
#else
    Server svr;
#endif

    if (!svr.is_valid()) {
        printf("server has an error...\n");
        return -1;
    }

    //svr.set_keep_alive_max_count(2); // Default is 5
    //svr.set_keep_alive_timeout(10);  // Default is 5

    svr.Get("/BigFile", [](const Request& req, Response& res) {
        checkFileStatus(req, res);
        });

    svr.Get("/", [=](const Request & /*req*/, Response &res) {
        res.set_redirect("/hi");
    });

    svr.Get("/hi", [](const Request & /*req*/, Response &res) {
        res.set_content("Hello World!\n", "text/plain");
    });

    svr.Get("/slow", [](const Request & /*req*/, Response &res) {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        res.set_content("Slow...\n", "text/plain");
    });

    svr.Get("/dump", [](const Request &req, Response &res) {
        res.set_content(dump_headers(req.headers), "text/plain");
    });

    svr.Get("/stop",
          [&](const Request & /*req*/, Response & /*res*/) { svr.stop(); });

    svr.set_error_handler([](const Request & /*req*/, Response &res) {
        const char *fmt = "<p>Error Status: <span style='color:red;'>%d</span></p>";
        char buf[BUFSIZ];
        snprintf(buf, sizeof(buf), fmt, res.status);
        res.set_content(buf, "text/html");
    });

    svr.set_logger([](const Request &req, const Response &res) {
        printf("%s", log(req, res).c_str());
    });

    svr.listen("localhost", 8080);

    return 0;
}
