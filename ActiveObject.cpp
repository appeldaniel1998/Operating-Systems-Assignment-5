
#include "ActiveObject.h"

void ActiveObject::run() {
    while (running_) {
        try {
            auto task = task_queue_.pop();
            task();
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
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