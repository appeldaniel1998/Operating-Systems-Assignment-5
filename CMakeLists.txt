cmake_minimum_required(VERSION 3.24)
project(assignment5)

set(CMAKE_CXX_STANDARD 17)

add_executable(assignment5 server/SafeQueue.h server/ActiveObject.cpp server/ActiveObject.h server/Pipeline.cpp server/Pipeline.h server/Reactor.cpp server/Reactor.h server/main.cpp)# TCPClient.cpp mainClient.cpp)
