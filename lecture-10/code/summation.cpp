#include <iostream>
#include <ctime>

int main() {
  std::clock_t start = std::clock();
  int sum = 0;
  for(int n = 0; n < 1000000; n++) {
    sum++;
  }
  double duration = (std::clock()-start) / (double) CLOCKS_PER_SEC;

  std::cout << sum << std::endl;
  std::cout << "time = " << duration << std::endl;

  return 0;
}
