#include <iostream>

int sum(int a, int b) {
  int c = a + b;
  return c;
}

int main() {
  int a = 2, b = 3;
  
  int c = sum(a,b);
  std::cout << "c = " << c << std::endl;
  
  return 0;
}
