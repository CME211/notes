#include <iostream>
#include <map>

// Topics covered in this example:
// 1. standard C++ maps

int main()
{
  std::map<char,std::string> dir;

  dir['A'] = std::string("south");
  dir['B'] = std::string("north");
  dir['C'] = std::string("east");
  dir['D'] = std::string("west");

  std::cout << "dir[C] = " << dir['C'] << std::endl;
  std::cout << "dir[A] = " << dir['A'] << std::endl;

  return 0;
}
