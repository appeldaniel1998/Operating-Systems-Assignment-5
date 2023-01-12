//
// Created by appeldaniel on 1/12/23.
//

#include "Reactor.h"

Reactor::Reactor(int maxConnections, int buffSize) {
    this->maxConnections = maxConnections;
    this->buffSize = buffSize;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        std::cerr << "Error opening socket" << std::endl;
        exit(1);
    }

    // Bind the socket to all IP addresses and any port
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(0);
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        std::cerr << "Error binding socket" << std::endl;
        exit(1);
    }

    // Get the port number that the socket is bound to
    socklen_t len = sizeof(serv_addr);
    if (getsockname(sockfd, (struct sockaddr *) &serv_addr, &len) < 0) {
        std::cerr << "Error getting socket name" << std::endl;
        exit(1);
    }
    int port = ntohs(serv_addr.sin_port);

    // Listen for incoming connections
    listen(sockfd, this->maxConnections);
    clilen = sizeof(cli_addr);
    std::cout << "Server listening on all IPs on port " << port << endl;
}

void Reactor::start() {
    while (this->stopFlag) {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            std::cerr << "Error on accept" << std::endl;
            exit(1);
        }

        // Print out client IP and port
        char client_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &(cli_addr.sin_addr), client_ip, INET_ADDRSTRLEN);
        std::cout << "Incoming connection from " << client_ip << ":" << ntohs(cli_addr.sin_port) << std::endl;

        // Read data from the client
        char buffer[this->buffSize];
        int n = read(newsockfd, buffer, this->buffSize - 1);
        if (n < 0) {
            std::cerr << "Error reading from socket" << std::endl;
            exit(1);
        }
        buffer[n] = '\0';
        std::cout << "Received message: " << buffer << std::endl;

        // Write data back to the client
        std::string message = "Server received your message: " + std::string(buffer);
        n = write(newsockfd, message.c_str(), message.length());
        if (n < 0) {
            std::cerr << "Error writing to socket" << std::endl;
            exit(1);
        }

        close(newsockfd);
    }
    close(sockfd);
}

void Reactor::stop() {
    this->stopFlag = false;
}
