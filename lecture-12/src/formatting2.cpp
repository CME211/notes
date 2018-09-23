#include <iostream>

int main() {
  double a = 2.;
  std::cout.setf(std::ios::showpoint);
  std::cout << "a = " << a << std::endl;
  return 0;
}
