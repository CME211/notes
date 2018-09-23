#include <iostream>

int main() {
  // declare a 2D array
  int a[2][2];

  // declare another 2D array
  int b[2][2];

  b = a;

  a[0][0] = 0;
  a[1][0] = 1;
  a[0][1] = 2;
  a[1][1] = 3;

  std::cout << "a = " << a << std::endl;
  std::cout << "b = " << b << std::endl;

  std::cout << "a[0][0] = " << a[0][0] << std::endl;
  std::cout << "a[1][0] = " << a[1][0] << std::endl;
  std::cout << "a[0][1] = " << a[0][1] << std::endl;
  std::cout << "a[1][1] = " << a[1][1] << std::endl;

  return 0;
}
