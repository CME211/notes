#include <stdio.h>

int main()
{
  unsigned int sum = 0;
  for (unsigned int n = 0; n < 101; n++)
  {
    sum += n;
  }
  printf("sum = %d\n", sum);

  return 0;
}
