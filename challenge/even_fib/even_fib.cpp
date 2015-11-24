#include <iostream>

int even_fib(int n) {
  int sum = 0;
  int m2 = 0;
  int m1 = 1;
  int m0 = m1 + m2;
  
  while (true) {
#ifdef DEBUG
    std::cout << "m0 = " << m0 << std::endl;
#endif
    // check limit on sequence
    if (m0 > n) {
      break;
    }
    // update sum if even
    if (m0 % 2 == 0) {
      sum += m0;
    }
    // update fib sequence
    m2 = m1;
    m1 = m0;
    m0 = m1 + m2;
  }
  
  return sum;
}

int main() {
  std::cout << even_fib(50) << std::endl;
  return 0;
}
