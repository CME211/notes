#include <iostream>

#define sqr(n) (n)*(n)

int main() {
  int a = 2;

  int b = sqr(a);
  std::cout << "b = " << b << std::endl;

  return 0;
}
