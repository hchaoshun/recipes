template <typename T>
class SmartPtr {
public:
    SmartPtr(T *p) : ptr_(p), count_(new size_t(1)) {}

    SmartPtr(const SmartPtr &sp) : ptr_(sp.ptr_), count_(sp.count_) {
        ++(*count_);
    }

    SmartPtr &operator=(const SmartPtr &sp) {
        if (this == &sp) return *this;  // 自赋值检查

        // 先减少当前对象的引用计数并清理资源
        if (--(*count_) == 0) {
            delete ptr_;
            delete count_;
        }

        // 复制新对象的指针和引用计数
        ptr_ = sp.ptr_;
        count_ = sp.count_;
        ++(*count_);

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
