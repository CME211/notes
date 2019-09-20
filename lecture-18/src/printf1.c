#include <stdio.h>

int main(int argc, char *argv[])
{
  int a = 2;
  double b = 3.14;

  printf("a = %d\n", a);
  printf("b = %.1f\n", b);
  printf("argc = %d\n", argc);
  printf("argv[0] = %s\n", argv[0]);
  printf("a = %d, b = %f, argv[0] = %s\n", a, b, argv[0]);
  fflush(stdout);

  return 0;
}
