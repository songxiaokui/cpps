//
// Created by 宋晓奎 on 2024/1/2.
//

#ifndef NETWORKPROGRAMING_SERVER_H
#define NETWORKPROGRAMING_SERVER_H

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <event2/event.h>
#include <event2/event.h>
#include <event2/buffer.h>
#include <event2/http.h>
#include <event2/http_struct.h>

void hello_world_cb(struct evhttp_request *req, void *arg);

int server(void);

#endif //NETWORKPROGRAMING_SERVER_H
