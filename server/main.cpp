#include <iostream>
#include "Reactor.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Wrong number of arguments passed" << endl;
        exit(1);
    }
    int numOfConnections = atoi(argv[1]);
    if (numOfConnections < 2 || numOfConnections > 10) {
        cerr << "Number of connections should be between 2 and 10 (inclusive)" << endl;
        exit(1);
    }
    TCPServer server(numOfConnections);
    server.Start(20002);

    return 0;
}
