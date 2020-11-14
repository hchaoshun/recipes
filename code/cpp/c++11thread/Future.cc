#include <iostream>
#include <exception>
#include <thread>
#include <future>

unsigned long Calculate(int n) {
  unsigned long result = 1;
  for (int i = 1; i <= n; i++)
    result *= i;
  std::this_thread::sleep_for(std::chrono::seconds(10));
  return result;
}

int main() {
  std::future<unsigned long> f = std::async(Calculate, 20);
  std::cout << "wait..." << std::endl;
  auto r = f.get();

  std::cout << r << std::endl;

  return 0;
}
