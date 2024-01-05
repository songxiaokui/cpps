//
// Created by 宋晓奎 on 2024/1/2.
//
#include "server.h"

using std::cout;
using std::endl;

void hello_world_cb(struct evhttp_request *req, void *arg) {
    struct evbuffer *buf = evbuffer_new();
    if (buf == nullptr) {
        evhttp_send_error(req, HTTP_INTERNAL, "Failed to create response buffer");
        return;
    }

    evbuffer_add_printf(buf, "Hello, World!\n");
    evhttp_send_reply(req, HTTP_OK, "OK", buf);
    evbuffer_free(buf);
}



int server(void) {
    struct event_base *base = event_base_new();
    if (!base) {
        fprintf(stderr, "Error creating event base\n");
        return EXIT_FAILURE;
    }

    struct evhttp *http = evhttp_new(base);
    if (!http) {
        fprintf(stderr, "Error creating evhttp structure\n");
        return EXIT_FAILURE;
    }

    evhttp_set_cb(http, "/api/hello", hello_world_cb, nullptr);

    if (evhttp_bind_socket(http, "127.0.0.1", 8080) != 0) {
        fprintf(stderr, "Error binding to port 8080\n");
        return EXIT_FAILURE;
    }

    event_base_dispatch(base);

    evhttp_free(http);
    event_base_free(base);

    return EXIT_SUCCESS;
}
