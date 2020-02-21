//设计一个不能被继承的类
class SealedClass {
public:
    static SealedClass *GetInstance() {
        if (instance_ == nullptr) {
            instance_ = new SealedClass();
        }
        return instance_;
    }

    static void Destroy() {
        if (instance_ != nullptr) {
        delete instance_;
        }
    }

private:
    SealedClass() {}
    ~SealedClass() {}

    static SealedClass *instance_;
};

SealedClass *SealedClass::instance_ = nullptr;


int main() {
    SealedClass *ptr = SealedClass::GetInstance();
    SealedClass::Destroy();

    ptr = nullptr;
}
