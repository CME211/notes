#include <iostream>
#include <string>

class user
{
  int id;
  std::string name;
};

int main()
{
  user u;
  u.id = 7; // Member access via dot notation
  std::cout << "u.id = " << u.id << std::endl;
  return 0;
}
