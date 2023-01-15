//
// Created by appeldaniel on 1/12/23.
//

#ifndef ASSIGNMENT5_ACTIVEOBJECT_H
#define ASSIGNMENT5_ACTIVEOBJECT_H


#include <thread>
#include <atomic>
#include <functional>
#include <iostream>
#include "SafeQueue.h"

using namespace std;

class ActiveObject {
private:
    thread thread_;
    SafeQueue<std::function<void()>> task_queue_;
    atomic<bool> running_;
    void run();

public:
    ActiveObject() : running_(false) {}
    void start();
    void stop();
    void AddTask(std::function<void()> task);
};


#endif //ASSIGNMENT5_ACTIVEOBJECT_H
