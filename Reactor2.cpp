//
// Created by appeldaniel on 1/12/23.
//

#include "Reactor2.h"

void TCPServer::HandleConnection() {
    int newsockfd;
    socklen_t clilen;
    struct sockaddr_in cli_addr;

    while (running_) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd_, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            std::cerr << "Error on accept" << std::endl;
            continue;
        }

// Print out client IP and port
        char client_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &(cli_addr.sin_addr), client_ip, INET_ADDRSTRLEN);
        std::cout << "Incoming connection from " << client_ip << ":" << ntohs(cli_addr.sin_port) << std::endl;

// Read data from the client
        char buffer[kBufferSize];
        int n = read(newsockfd, buffer, kBufferSize - 1);
        if (n < 0) {
            std::cerr << "Error reading from socket" << std::endl;
            continue;
        }
        buffer[n] = '\0';
        std::cout << "Received message: " << buffer << std::endl;

// Write data back to the client
        std::string message = "Server received your message: " + std::string(buffer);
        n = write(newsockfd, message.c_str(), message.length());
        if (n < 0) {
            std::cerr << "Error writing to socket" << std::endl;
            continue;
        }

        close(newsockfd);
    }
}

bool TCPServer::Start(int port) {
    {
        if (running_) {
            std::cerr << "Server is already running" << std::endl;
            return false;
        }

        // Create a socket
        sockfd_ = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd_ < 0) {
            std::cerr << "Error opening socket" << std::endl;
            return false;
        }

        // Bind the socket to all IP addresses and the given port
        bzero((char *) &serv_addr_, sizeof(serv_addr_));
        serv_addr_.sin_family = AF_INET;
        serv_addr_.sin_addr.s_addr = INADDR_ANY;
        serv_addr_.sin_port = htons(port);
        if (bind(sockfd_, (struct sockaddr *) &serv_addr_, sizeof(serv_addr_)) < 0) {
            std::cerr << "Error binding socket" << std::endl;
            return false;
        }

        // Listen for incoming connections
        listen(sockfd_, kMaxConnections);

        running_ = true;
        thread_ = std::thread(&TCPServer::HandleConnection, this);

        return true;
    }
}

void TCPServer::Stop() {
    if (!running_) {
        return;
    }
    // Send a stop signal to the connection handling thread
    running_ = false;
    thread_.join();

    close(sockfd_);
}