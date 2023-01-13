//
// Created by appeldaniel on 1/12/23.
//

#ifndef ASSIGNMENT5_REACTOR_H
#define ASSIGNMENT5_REACTOR_H

#include <iostream>
#include <string>
#include <thread>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include "Pipeline.h"

class TCPServer {
private:
    void HandleConnection();

    bool running_;
    int sockfd_;
    struct sockaddr_in serv_addr_;
    std::thread thread_;
    int kMaxConnections;
    int kBufferSize;
    Pipeline pipeline;

    TCPServer(const TCPServer &) = delete;
    TCPServer &operator=(const TCPServer &) = delete;

public:
    TCPServer(int max_connections = 10, int buffer_size = 1024)
    {
        running_ = false;
        kMaxConnections = max_connections;
        kBufferSize = buffer_size;
    }
    ~TCPServer() {
        Stop();
    }
    bool Start(int port);
    void Stop();

};


#endif //ASSIGNMENT5_REACTOR_H
