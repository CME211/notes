#include <iostream>

int main() {
  double a = 2., b = 3.14;
  int c = 4;
  
  //Always show 3 decimal places
  std::cout.setf(std::ios::fixed, std::ios::floatfield);
  std::cout.setf(std::ios::showpoint);
  std::cout.precision(3);
  
  std::cout << "a = " << a << std::endl;
  std::cout << "b = " << b << std::endl;
  std::cout << "c = " << c << std::endl;
  
  return 0;
}
