#include <stdio.h>

#include <stdlib.h> // to get prototypes for malloc() and free()

int main() {

  // in C, initialize pointers to NULL
  double *a = NULL;

  // Use sizeof() function to get number of bytes required to store a double
  a = (double *)malloc(4*sizeof(double));

  a[0] = 0.; a[1] = 1.; a[2] = 2.; a[3] = 3.; 

  printf("a[0] = %f\n", a[0]);
  printf("a[1] = %f\n", a[1]);
  printf("a[2] = %f\n", a[2]);
  printf("a[3] = %f\n", a[3]);

  // Free memory when done with it
  free(a);
  // clear out your pointer
  a = NULL;

  return 0;
}
