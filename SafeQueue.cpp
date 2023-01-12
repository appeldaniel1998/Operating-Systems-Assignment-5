
#include "SafeQueue.h"

template <typename T>
T SafeQueue<T>::pop() {
    unique_lock<std::mutex> mlock(mutex_);
    while (queue_.empty()) {
        cond_.wait(mlock);
    }
    auto item = queue_.front();
    queue_.pop();
    return item;
}

template <typename T>
void SafeQueue<T>::push(const T &item) {
    unique_lock<std::mutex> mlock(mutex_);
    queue_.push(item);
    mlock.unlock();
    cond_.notify_one();
}

template <typename T>
void SafeQueue<T>::pop(T &item) {
    unique_lock<std::mutex> mlock(mutex_);
    while (queue_.empty()) {
        cond_.wait(mlock);
    }
    item = queue_.front();
    queue_.pop();
}

template <typename T>
void SafeQueue<T>::push(T &&item) {
    unique_lock<std::mutex> mlock(mutex_);
    queue_.push(std::move(item));
    mlock.unlock();
    cond_.notify_one();
}

template <typename T>
int SafeQueue<T>::size() {
    unique_lock<std::mutex> mlock(mutex_);
    int size = queue_.size();
    mlock.unlock();
    return size;
}