#include <iostream>

void plus2(int* a, int N)
{
  for(int i = 0; i < N; ++i)
  {
    a[i] += 2;
  }
}

void print_array(int const* a, int N)
{
  for(int i = 0; i < N; ++i)
  {
    std::cout << a[i] << "\n";
  }
  //a[0] = 5; // compiler error
}

int main()
{
  int N = 5;
  int* x = new int[N];

  for(int i=0; i<N; ++i)
    x[i] = i*2;
  std::cout << "\nPrint array:\n";
  print_array(x, N);

  plus2(x, N);
  std::cout << "\nPrint array + 2:\n";
  print_array(x, N);

  delete [] x;

  return 0;
}

  
