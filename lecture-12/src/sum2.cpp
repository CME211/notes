#include <iostream>

int main() {
  int a = 2, b = 3;

  // the compiler does not yet know about sum()
  int c = sum(a,b);
  std::cout << "c = " << c << std::endl;
  
  return 0;
}

int sum(int a, int b) {
  int c = a + b;
  return c;
}
