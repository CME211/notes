#include <iostream>

int main() 
{
  const int a = 2; // The two definitions are equivalent and
  int const b = 3; // specify constant integers.

  int c = a + b;
  std::cout << "c = " << c << std::endl;
  
  a = 3; // triggers compiler error

  return 0;
}
