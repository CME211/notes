#include <iostream>
#include <vector>

#include "circle3.hpp"

int main() {
  std::vector<geometry::circle> circles;
  circles.emplace_back(8.3, 4.7, 0.5);
  circles.emplace_back(4.1, 2.3, 1.4);
  circles.emplace_back(-3.2, 0.8, 14.4);

  for(auto& c : circles) {
    std::cout << "c.getArea() = " << c.getArea() << std::endl;
  }
  
  return 0;
}
