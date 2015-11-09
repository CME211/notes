#include <iostream>
#include <map>

int main()
{
  std::map<int,std::string> dir;

  dir[0] = std::string("north");
  dir[1] = std::string("east");
  dir[2] = std::string("south");
  dir[3] = std::string("west");

  std::cout << "dir.count(2) = " << dir.count(2) << std::endl;
  std::cout << "dir.count(5) = " << dir.count(5) << std::endl;

  return 0;
}
