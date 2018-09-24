#include <iostream>

#include "circle2.hpp"

int main() {
  circle c(1.2, 3.4, 2.);
  std::cout << "c.getArea() = " << c.getArea() << std::endl;
  return 0;
}
