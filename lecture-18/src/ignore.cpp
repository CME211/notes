#include <iostream>

int sum(int a, int b) {
  int c = a + b;
  return c;
}

int main() {
  int a = 2, b = 3;
  
  sum(a,b); // legal to ignore return value if you want
  
  return 0;
}
