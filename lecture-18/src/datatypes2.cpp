#include <iostream>

int sum(int a, int b) {
  double c = a + b;
  return c; // we are not returning the correct type
}

int main() {
  double a = 2.7, b = 3.8;
  
  int c = sum(a,b);
  std::cout << "c = " << c << std::endl;
  
  return 0;
}
