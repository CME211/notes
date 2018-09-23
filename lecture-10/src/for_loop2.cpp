#include <iostream>

int main() {
  int n, sum;

  sum = 0;
  for (n = 0; n < 101; ++n) {
    sum += n;
  }

  std::cout << "sum = " << sum << std::endl;
  return 0;
}
