#include <iostream>
#include <map>

int main()
{
  std::map<int,std::string> dir;

  dir[2] = std::string("south");
  dir[3] = std::string("west");
  dir[1] = std::string("east");
  dir[0] = std::string("north");

  for (auto &d : dir)
    std::cout << d.first << std::endl;

  return 0;
}
