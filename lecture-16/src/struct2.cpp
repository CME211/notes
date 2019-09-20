#include <iostream>
#include <string>

struct user {
  int id;
 private: // everything after this will be private
  std::string name;
};

int main() {
  user u;
  u.id = 7;
  u.name = "Leland";
  std::cout << "u.id = " << u.id << std::endl;
  std::cout << "u.name = " << u.name << std::endl;
  return 0;
}
