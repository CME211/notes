#include <iostream>

#include "circle3.hpp"

int main() {
  geometry::circle c(1.2, 3.4, 1.8);
  std::cout << "c.getArea() = " << c.getArea() << std::endl;
  std::cout << "c.getPerimeter() = " << c.getPerimeter() << std::endl;
  return 0;
}
