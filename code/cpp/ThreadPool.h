//
// Created by hcs on 25-4-7.
//

#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <pthread.h>

struct Task {
  function<void*> func;
  void* arg;
}

class ThreadPool {
  public:
    ThreadPool(size_t num): stop_(false) {
      pthread_mutex_init(&mutex_, nullptr);
      pthread_cond_init(&cond_, nullptr);

      for (size_t i = 0; i < num; ++i) {
        pthread_t thread;
        pthread_create(&thread, nullptr, worker, this);
        threads_.push_back(thread);
      }
    }

    void *worker(void *arg) {
      ThreadPool *pool = static_cast<ThreadPool*>(arg);
      pool->run();
      return nullptr;
    }

    void run() {
      while (true) {
        pthread_mutex_lock(&mutex_);
        while (!q_.empty() && !stop_) {
          pthread_cond_wait(&cond_, &mutex_);
        }
        Task task = q_.front();
        q_.pop_front();
        pthread_mutex_unlock(&mutex_);
        task->func(task->arg);
      }
    }

    void enqueue(function<void*> func, void*arg) {
      Task task(func, arg);
      pthread_mutex_lock(&mutex_);
      q_.push_back(task);
      pthread_cond_signal(&cond_);
      pthread_mutex_unlock(&mutex_);
    }


    ~ThreadPool() {
      pthread_mutex_lock(&mutex_);
      stop_ = true;
      pthread_cond_broadcast(&cond_);
      pthread_mutex_unlock(&mutex_);

      for (size_t i = 0; i < threads_.size(); ++i) {
        pthread_join(threads_[i], nullptr);
      }

      pthread_mutex_destroy(&mutex_);
      pthread_cond_destroy(&cond_);
    }

  private:
    pthread_mutex_t mutex_;
    pthread_cond_t cond_;
    std::vector<pthread_t> threads_;
    std::queue<Task> q_;
    bool stop_;

};



#endif //THREADPOOL_H
