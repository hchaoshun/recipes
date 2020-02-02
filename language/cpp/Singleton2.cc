template <typename T>
class Singleton {
public:
    static T& getValue() {
        pthread_once(&init_done_, &Singleton::init);
        return *value_;
    }

private:
    Singleton() {}
    ~Singleton() {}

    static void init() {
        value_ = new T();
    }

private:
    static T* value_;
    static pthread_once_t init_done_;
};

template <typename T>
T* Singleton<T>::value_ = nullptr;

template <typename T>
pthread_once_t Singleton<T>::init_done_ = PTHREAD_ONCE_INIT;
