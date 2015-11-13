#include <iostream>

#include "sum.hpp"

int main() {
  double a = 2., b = 3., c;

  c = sum(a,b);
  std::cout << "c = " << c << std::endl;

  return 0;
}
