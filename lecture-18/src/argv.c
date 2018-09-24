#include <stdio.h> // for printf
#include <stdlib.h> // for ato{i,f}

int main(int argc, char *argv[]) {
  if (argc < 4) return 1;
  char *file = argv[1];
  int n = atoi(argv[2]);
  double threshold = atof(argv[3]); 
  printf("file = %s\n", file);
  printf("n = %d\n", n);
  printf("threshold = %f\n", threshold);
  return 0;
}
