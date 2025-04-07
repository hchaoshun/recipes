#ifndef THREADSAFEQUEUE_H
#define THREADSAFEQUEUE_H

#include <pthread.h>
#include <deque>

template <typename T>
class ThreadSafeQueue {
public:
    ThreadSafeQueue() {
        pthread_mutex_init(&mutex_, nullptr);
        pthread_cond_init(&cond_, nullptr);
    }

    ~ThreadSafeQueue() {
        pthread_mutex_destroy(&mutex_);
        pthread_cond_destroy(&cond_);
    }

    void push(T t) {
        pthread_mutex_lock(&mutex_);
        q_.push_back(t);
        pthread_cond_signal(&cond_);
        pthread_mutex_unlock(&mutex_);
    }

    T pop() {
        pthread_mutex_lock(&mutex_);
        while (q_.empty()) {
            pthread_cond_wait(&cond_, &mutex_);
        }
        T r = q_.front();
        q_.pop_front();
        pthread_mutex_unlock(&mutex_);
        return r;
    }

    int size() {
        pthread_mutex_lock(&mutex_);
        int s = q_.size();
        pthread_mutex_unlock(&mutex_);
        return s;
    }

private:
    std::deque<T> q_;
    pthread_mutex_t mutex_;
    pthread_cond_t cond_;
};

#endif // THREADSAFEQUEUE_H
