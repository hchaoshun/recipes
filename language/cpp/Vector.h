template <typename T>
class Vector {
    public:
        Vector(): start_(nullptr), cur_(nullptr), cap_(nullptr) {}
        Vector(const Vector<T> &);
        Vector<T> &operator=(const Vector<T> &);
        ~Vector();

        void push_back(T &data);
        size_t size() const {return cur_ - start_;}
        size_t capacity() const {return cap_ - start_;}

    private:
        void chk_and_realloc() {
            if (size() == capacity()) {
                realloc();
            }
        }
        void realloc();
        void free();

        allocator<T> alloc;
        T *start_;
        T *cur_;
        T *cap_;
};

template <typename T>
void Vector<T>::push_back(T &data) {
    chk_and_realloc();
    alloc.construct(cur_++, data);
}

template <typename T>
void Vector<T>::realloc() {
    auto new_size = size() ? capacity() * 2 : 1;
    auto p = alloc.allocate(new_size);
    auto q = p;
    for (size_t i = 0; i != size(); ++i) {
        alloc.construct(p++, std::move(*(start_ + i)));
    }
    free();
    start_ = q;
    cur_ = p;
    cap_ = p + new_size;
}

template <typename T>
void Vector<T>::free() {
    if (start_) {
        while (cur_ != start_) {
            alloc.destroy(--cur_);
        }
    alloc.deallocate(start_, cap_ - start_);
    }
}








