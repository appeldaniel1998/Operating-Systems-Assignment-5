#include <iostream>
#include "ActiveObject.h"
#include "Reactor.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Wrong number of arguments passed" << endl;
    }
    int numOfConnections = atoi(argv[1]);
    if (numOfConnections < 2 || numOfConnections > 10) {
        cerr << "Number of connections should be between 2 and 10 (inclusive)" << endl;
    }
    TCPServer server(numOfConnections);
    server.Start(20001);

    return 0;
}
