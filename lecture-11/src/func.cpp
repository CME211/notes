#include <iostream>

int* func(void) {
  int b = 2;
  return &b;
}

int main() {
  int *a = func();

  std::cout << " a = " << a << std::endl;
  std::cout << "*a = " << *a << std::endl;

  return 0;
}
