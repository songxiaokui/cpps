//
// Created by 宋晓奎 on 2024/1/22.
//

#include "hvserver.h"

int run(void) {
    int port = 8894;
    std::cout << "Service Running..." << std::endl;
    HttpService service;
    service.base_url = "/api";
    service.GET("/test", [](HttpRequest *req, HttpResponse *resp) {
        resp->body = "hello post server!";
        return 200;

    });

    http_server_t server;
    server.port = port;
    server.service = &service;
    http_server_run(&server);
    return 0;
}