#include <iostream>

int sum(int a, int b) {
  double c = a + b;
  return (int)c;
}

int main() {
  double a = 2.7, b = 3.8;
  
  int c = sum((int)a,(int)b);
  std::cout << "c = " << c << std::endl;
  
  return 0;
}
