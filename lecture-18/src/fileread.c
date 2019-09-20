#include <stdio.h>

int main()
{
  FILE *f = NULL;
  float a; 

  char file[] = "numbers.txt";
  if ((f = fopen(file, "r")) == NULL)
  {
    printf("Error opening %s\n", file);
    return 0;
  }

  while(fscanf(f, "%f\n", &a) = EOF) {
    printf("%f\n", a);
  }

  fclose(f);
  f = NULL;

  return 0;
}
