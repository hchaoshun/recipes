#include <iostream>

struct B;
struct A {
  std::shared_ptr<struct B> m_pa;
};

struct A;
struct B {
  std::shared_ptr<struct A> m_pb;
};

struct WB;
struct WA {
  std::weak_ptr<struct WB> mw_pb;
};

struct WA;
struct WB {
  std::weak_ptr<struct WA> mw_pa;
};

void test_leak() {
  std::weak_ptr<struct A> wp1;

  {
    auto pa = std::make_shared<struct A>();
    auto pb = std::make_shared<struct B>();

    pa->m_pa = pb;
    pb->m_pb = pa;

    wp1 = pa;

    std::cout << "before: " << wp1.use_count() << std::endl;
  }
  std::cout << "after: " << wp1.use_count() << std::endl;

  std::weak_ptr<struct WA> wp2;
  {
    auto pa = std::make_shared<struct WA>();
    auto pb = std::make_shared<struct WB>();

    pa->mw_pb = pb;
    pb->mw_pa = pa;

    wp2 = pa;

    std::cout << "before: " << wp2.use_count() << std::endl;
  }
  std::cout << "after: " << wp2.use_count() << std::endl;

}

int main() {
  test_leak();
  return 0;
}

