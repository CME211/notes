#include <iostream>

int add(int a, int b) {
  return a + b;
}

int main(int argc, char* argv[]) {
  int a, b;
  a = atoi(argv[1]);
  b = atoi(argv[2]);
  int c = add(a, b);
  std::cout << c << std::endl;
  return 0;
}
