#include <iostream>

int main()
{
  int a = 4;
  int c = 5;
  const int* b = &a; // cannot change data pointed by b
  int* const d = &c; // cannot change address stored in d
  
  std::cout << "*b = " << *b << "\n";
  std::cout << "*d = " << *d << "\n\n";
  
  *b = c; // compiler error
  b = &c;  
  std::cout << "*b = " << *b << "\n\n";

  d = &a; // compiler error
  *d = a;
  std::cout << "*d = " << *d << "\n";
  
  
  return 0;
}
