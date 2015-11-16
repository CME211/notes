#include <iostream>
#include <string>

struct user
{
  int id;
  std::string name;
};

int main()
{
  user u;
  u.id = 7;
  std::cout << "u.id = " << u.id << std::endl;
  return 0;
}
