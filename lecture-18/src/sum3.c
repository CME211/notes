#include <stdio.h>

int main()
{
  // change type to double
  double a = 2, b = 3, c;
  c = sum(a,b); // Calling a function the compiler has no knowledge of
  printf("c = %f\n", c);
  return 0;
}

double sum(double a, double b)
{
  double c;
  c = a + b;
  return c;
}
