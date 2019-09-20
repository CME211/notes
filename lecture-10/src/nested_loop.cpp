#include <iostream>

int main() {
  double a[3][3];

  /* Initialize a to zeros. */

  for (int n = 0, i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      a[i][j] = n;
      n++;
    }
  }

  /* Print a. */

  for (int i = 0; i < 3; i++) {
    std::cout << a[i][0];
    for (int j = 1; j < 3; j++) {
      std::cout << " " << a[i][j];
    }
    std::cout << std::endl;
  }

  return 0;
}
