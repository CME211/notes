#include <stdio.h>

int sum(int a, int b)
{
  int c;
  c = a + b;
  return c;
}

int main()
{
  int a = 2, b = 3, c;

  c = sum(a,b);
  printf("c = %d\n", c);

  return 0;
}
