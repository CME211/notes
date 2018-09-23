#include <iostream>

int main() {
  int n = 5;
  double a[16];

  /* Initialize a to zeros. */

  for (int n = 0; n < 16; n++) {
    a[n] = 0.;
  }

  std::cout << "a[0] = " << a[0] << std::endl;
  std::cout << "n = " << n << std::endl;

  return 0;
}
