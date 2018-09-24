#include <stdio.h>

int main() {
  int n, sum;
  sum = 0;
  for (n = 0; n < 101; n++) {
    sum += n;
  }
  printf("sum = %d\n", sum);
  return 0;
}
