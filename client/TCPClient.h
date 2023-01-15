//
// Created by appeldaniel on 1/13/23.
//

#ifndef ASSIGNMENT5_TCPCLIENT_H
#define ASSIGNMENT5_TCPCLIENT_H


#include <iostream>
#include <iostream>
#include <string>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

class TCPClient {
private:
    std::string host;
    int port;

public:
    TCPClient(std::string host, int port);
    void start();
};


#endif //ASSIGNMENT5_TCPCLIENT_H
