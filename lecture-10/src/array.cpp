#include <iostream>

int main() {
  // Array referenced via a with 3 integer elements
  int a[3];

  // note: in the above declaration of a, the size (3) may not be a variable

  a[0] = 0;
  a[1] = a[0] + 1;
  a[2] = a[1] + 1;
  a[3] = a[2] + 1; // Out of bounds access

  std::cout << "a[0] = " << a[0] << std::endl;
  std::cout << "a[1] = " << a[1] << std::endl;
  std::cout << "a[2] = " << a[2] << std::endl;
  std::cout << "a[3] = " << a[3] << std::endl;

  return 0;
}
