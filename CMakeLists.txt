cmake_minimum_required(VERSION 3.24)
project(assignment5)

set(CMAKE_CXX_STANDARD 17)

add_executable(assignment5 SafeQueue.h ActiveObject.cpp ActiveObject.h Pipeline.cpp Pipeline.h Reactor.cpp Reactor.h main.cpp)# TCPClient.cpp mainClient.cpp)
