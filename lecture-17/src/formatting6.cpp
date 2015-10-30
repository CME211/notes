#include <iostream>

int main() {
  double a = 2., b = 3.14;
  int c = 4;
  
  std::cout.setf(std::ios::scientific, std::ios::floatfield);
  std::cout.precision(3);
  
  std::cout << "a = " << a << std::endl;
  std::cout.width(15);
  std::cout << "b = " << b << std::endl;
  std::cout.width(30);
  std::cout << "c = " << c << std::endl;
  
  return 0;
}
