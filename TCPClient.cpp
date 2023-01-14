
#include "TCPClient.h"

TCPClient::TCPClient(std::string host, int port) {
    this->host = host;
    this->port = port;
}

void TCPClient::start() {
    // create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        std::cerr << "Failed to create socket" << std::endl;
        return;
    }

    // setup server address
    sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(host.c_str());
    server.sin_port = htons(port);

    // connect to server
    if (connect(sock, (sockaddr *) &server, sizeof(server)) < 0) {
        std::cerr << "Failed to connect to server" << std::endl;
        return;
    }

    while (true) {
        // get message from user
        std::string message;
        std::cout << "Enter message to send to server: ";
        std::getline(std::cin, message);


        //check if massage is 'quit'
        if (message == "quit") {
            message = "goodbye";
            if (send(sock, message.c_str(), message.size(), 0) < 0) {
                std::cerr << "Failed to send message to server" << std::endl;
                return;
            }
            std::cout << "goodbye sent to server, closing connection" << std::endl;
            break;
        } else if (send(sock, message.c_str(), message.size(), 0) < 0) { // send message to server
            std::cerr << "Failed to send message to server" << std::endl;
            return;
        }
        std::cout << "Message sent to server: " << message << std::endl;
    }

    close(sock);
}
