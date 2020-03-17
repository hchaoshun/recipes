#include "String.h"

String::String() data_(new char[1]) {
    *data_ = '\0';
}

String::String(const char *data) data_(new char[strlen(data)+1]) {
    strcpy(data_, data);
}

String::String(const String &str) data_(new char [str.size()+1]) {
    strcpy(data_, str.data_);
}

String::String(String &&str) noexcept data_(str.data_) {
    str.data_ = nullptr;
}

String &String::operator=(const String &str) {
    String tmp = str;
    delete []data_;
    data_ = new char[tmp.size()+1];
    strcpy(data_, tmp.data_);
    return *this;

    //if (this != &str) {
    //  delete []data_;
    //  data_ = new char[str.size()+1];
    //  strcpy(data_, str.data_);
    //}
    //return *this;


    //String tmp(str);
    //swap(*this, tmp);
    //return *this;
}

String &String::operator=(String str) {
    swap(str);
    return *this;
}

String &String::operator=(String &&str) {
    swap(str);
    return *this;
}

size_t String::size() const {
    return strlen(data_);
}

void swap(String &str) {
    using std::swap;
    swap(data_, str.data_);
}

String::~String() {
    delete []data_;
}
