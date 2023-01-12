//
// Created by appeldaniel on 1/12/23.
//

#include "ActiveObject.h"

void ActiveObject::run() {
    while (running_) {
        if (task_queue_.size() != 0) {
            auto task = task_queue_.pop();
            task();
        }
    }
}

void ActiveObject::start() {
    running_ = true;
    thread_ = std::thread(&ActiveObject::run, this);
}

void ActiveObject::stop() {
    running_ = false;
    thread_.join();
}

void ActiveObject::AddTask(std::function<void()> task) {
    task_queue_.push(task);
}