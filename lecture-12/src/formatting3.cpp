#include <iostream>

int main() {
  double a = 2., b = 3.14, c = 1.23456789, d = 12.3456789;
  int e = 4;

  std::cout.setf(std::ios_base::showpoint);

  std::cout << "a = " << a << std::endl;
  std::cout << "b = " << b << std::endl;
  std::cout << "c = " << c << std::endl;
  std::cout << "d = " << d << std::endl;
  std::cout << "e = " << e << std::endl;

  return 0;
}
