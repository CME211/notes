#include <iostream>

int main() {
  double a = 2., b = 3.14;
  int c = 4;
  
  std::cout.setf(std::ios::showpoint);
  
  std::cout << "a = " << a << std::endl;
  std::cout << "b = " << b << std::endl;
  std::cout << "c = " << c << std::endl;
  
  return 0;
}
