//
// Created by appeldaniel on 1/12/23.
//

#ifndef ASSIGNMENT5_REACTOR_H
#define ASSIGNMENT5_REACTOR_H

#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
using namespace std;

class Reactor {
private:
    int maxConnections;
    int buffSize;
    int sockfd;
    int newsockfd;
    socklen_t clilen;
    struct sockaddr_in serv_addr;
    struct sockaddr_in cli_addr;
    bool stopFlag = true;

public:
    Reactor(int maxConnections, int buffSize);
    void start();
    void stop();
};


#endif //ASSIGNMENT5_REACTOR_H
