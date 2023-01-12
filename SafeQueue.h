//
// Created by appeldaniel on 1/12/23.
//

#ifndef ASSIGNMENT5_SAFEQUEUE_H
#define ASSIGNMENT5_SAFEQUEUE_H


#include <queue>
#include <mutex>
#include <condition_variable>

using namespace std;

template<typename T>
class SafeQueue {
private:
    queue<T> queue_;
    mutex mutex_;
    condition_variable cond_;
public:
    T pop();
    void pop(T &item);
    void push(const T &item);
    void push(T &&item);
    int size();
};


#endif //ASSIGNMENT5_SAFEQUEUE_H
