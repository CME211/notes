#include <iostream>
#include <map>

int main()
{
  std::map<int,std::string> dir;

  dir[0] = std::string("north");
  dir[1] = std::string("east");
  dir[2] = std::string("south");
  dir[3] = std::string("west");

  for (auto d : dir)
    std::cout << "d[" << d.first << "] = " << d.second << std::endl;

  for (auto &d : dir)
    std::cout << "d[" << d.first << "] = " << d.second << std::endl;

  return 0;
}
