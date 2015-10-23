#include <iostream>

int main() {
  int a, b;

  a = (int)2.7; // int(2.7) would also work

  b = 3;
  int c = a + b;

  std::cout << "c = " << c << std::endl;

  return 0;
}
