class String {
public:
    String(): data_(new char[1]) {
        *data_ = '\0';
    }

    String(const char *data): data_(new char[strlen(data) + 1]) {
        strcpy(data_, data);
    }

    String(const String &str): data_(new char[strlen(str.data_) + 1]) {
        strcpy(data_, str.data_);
    }

    String(String &&str) noexcept : data_(str.data_) {
        str.data_ = nullptr;
    }

    String &operator=(const String &str) {
        if (this != &str) {
            String tmp(str);
            swap(tmp);
        }
        return *this;
    }

    String &operator=(String &&str) noexcept {
        if (this != &str) {
            delete[] data_;
            data_ = str.data_;
            str.data_ = nullptr;
        }
        return *this;
    }

    void swap(String &str) {
        std::swap(data_, str.data_);
    }

    size_t size() const {
        return strlen(data_);
    }

    ~String() {
        delete[] data_;
    }

private:
    char *data_;
};
