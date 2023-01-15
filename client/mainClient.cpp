#include "TCPClient.h"

//
// Created by appeldaniel on 1/13/23.
//
int main(int argc, char* argv[]) {
    TCPClient client("127.0.0.2", 20002); // replace with actual host and port of the server
    client.start();
}


