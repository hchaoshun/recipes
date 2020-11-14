class String {
public:
    String(): data_(new char[1]) {
        *data_ = '\0';
    }

    String(const char *data): data_(new char[strlen(data)+1]) {
        strcpy(data_, data);
    }

    String(const String &str): data_(new char[str.size()+1]) {
        strcpy(data_, str.data_);
    }

    String(String &&str): data_(str.data_) {
        str.data_ = nullptr;
    }
    String &operator=(const String &str) {
        String tmp(str);
        swap(tmp);
        return *this;
    }

    String &operator=(String &&str) {
        std::swap(str);
        return *this;
    }

    void swap(const String &str) {
        swap(*this, str);
    }

    size_t size() const {
        return strlen(data_);
    }

    ~String() {
        delete []data_;
    }

private:
    char *data_;
};
