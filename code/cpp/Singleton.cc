template <typename T>
class Singleton {
public:
    static T *getInstance() {
        if (instance_ == nullptr) {
            pthread_mutex_lock(&mutex_);
            if (instance_ == nullptr) {
                instance_ = new T();
            }
            pthread_mutex_unlock(&mutex_);
        }
        return instance_;
    }

private:
    Singleton() : {}
    static T *instance_;
    static pthread_mutex_t mutex_;
}

template <typename T>
T *Singleton<T>::instance_ = nullptr;

template <typename T>
pthread_mutex_t Singleton<T>::mutex_ = PTHREAD_MUTEX_INITIALIZER;
