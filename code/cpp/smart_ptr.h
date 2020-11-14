template <typename T>
class SmartPtr {
    public:
        SmartPtr(T *p): ptr_(p), count_(new size_t(1)) {}
        SmartPtr(const SmartPtr &sp): ptr_(sp.ptr_), count_(sp.count_) {
            ++(*count_);
        }
        SmartPtr &operator=(const SmartPtr &sp) {
            ++(*count_);
            if (--(*sp.count_) == 0) {
                delete sp.ptr_;
                delete sp.count_;
            }
            ptr_ = sp.ptr_;
            count_ = sp.count_;
            return *this;
        }
        ~SmartPtr() {
            if (--(*count_) == 0) {
                delete ptr_;
                delete count_;
            }
        }
    private:
        T *ptr_;
        size_t *count_;
};
