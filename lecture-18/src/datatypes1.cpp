#include <iostream>

int sum(int a, int b) {
  int c;
  c = a + b;
  return c;
}

int main() {
  double a = 2.7, b = 3.8;
  
  int c = sum(a,b);
  std::cout << "c = " << c << std::endl;
  
  return 0;
}
