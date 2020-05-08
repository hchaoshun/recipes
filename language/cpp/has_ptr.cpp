//shadow copy
class HasPtr {
    public:
        HasPtr(const string &s = string()):
            s_(new string(s)), i_(0), count_(new int(1)) {}
        HasPtr(const HasPtr &hp) : s_(hp.s_), i_(hp.i_), count_(hp.count_) {
            ++*count_;
        }
        HasPtr &operator=(const HasPtr &hp);
        ~HasPtr();

    private:
        string *s_;
        int i_;
        int *count_;
};

HasPtr::~HasPtr() {
    if (--*count_ <= 0) {
        delete s_;
        delete count_;
    }
}

HasPtr &HasPtr::operator=(HasPtr &hp) {
    ++hp.count_;
    if (--*count_ <= 0) {
        delete s_;
        delete count_;
    }
    s_ = hp.s_;
    i_ = hp.i_;
    count_ = hp.count_
    return *this;
}

//todo deep copy
class HasPtr {
    public:
        HasPtr(const string &s = string()): str_(new string(s)), i_(0) {}
        HasPtr(const HasPtr &hp): str_(new string(*hp.str_)), i_(hp.i_) {}
        HasPtr &operator=(const HasPtr &hp) {
            string *newp = new string(*hp.str_);
            delete str_;
            str_ = newp;
            i_ = hp.i_
            return *this;
        }
        ~HasPtr() {
            delete str_;
        }
    private:
        string *str_;
        size_t i;
};
