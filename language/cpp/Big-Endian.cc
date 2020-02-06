#include <iostream>
int main() {
  int i = 0x12345678;
  char *p = (char *)&i; //通过将int(4字节)强制类型转换成char单字节，p指向i的起始内存地址
  if (*p == 0x12) {
    std::cout << "big endian";
  } else {
    std::cout << "little endian";
  }
  return 0;
}
