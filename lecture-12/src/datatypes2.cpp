#include <iostream>

int sum(int a, int b) {
  double c = a + b;
  return c; // we are not returning the correct type
}

int main() {
  int a = 2, b = 3;
  int c = sum(a,b);
  std::cout << "c = " << c << std::endl;
}
