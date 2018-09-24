#include <stdio.h>

int main() {
  int n = 42;
  FILE *f = NULL; // Pointer to a file
  f = fopen("hello.txt", "w"); // Opens "hello.txt" for write
  if (f == NULL) // Make sure file was opened successfully
  {
    printf("Error: Failed to open file for write\n");
  }
  else
  {
    fprintf(f, "Hello\n");
    fprintf(f, "The answer is %d\n", n); // Print to file
    fprintf(f, "Goodbye\n");
    fclose(f); // close file
    f = NULL; // clear pointer
  }
  return 0;
}
