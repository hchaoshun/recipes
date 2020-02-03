template <typename T>
class BlockingQueue {
public:
    BlockingQueue() {}

    T pop() {
        pthread_mutex_lock(&mutex_);
        while (queue_.empty())
            pthread_cond_wait(&cond_, &mutex_);
        T data = queue_.front();
        queue_.pop_front();
        pthread_mutex_unlock(&mutex_);
        return data;
    }

    void push(T data) {
        pthread_mutex_lock(&mutex_);
        queue_.push_back(data);
        pthread_cond_signal(&cond_);
        pthread_mutex_unlock(&mutex_);
    }

    int size() {
        return queue_.size();
    }

private:
    std::deque<T> queue_;
    pthread_mutex_t mutex_;
    pthread_cond_t cond_;
};
