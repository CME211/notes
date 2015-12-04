#include <stdio.h>

int main()
{
  int a = 2, b = 3, c;

  c = sum(a,b); //Calling a function the compiler has no knowledge of

  printf("c = %d\n", c);

  return 0;
}

int sum(int a, int b)
{
  int c;
  c = a + b;
  return c;
}
