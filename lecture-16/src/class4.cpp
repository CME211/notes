#include <iostream>
#include <string>

class user {
  int id;
 public:
  std::string name;
 private:
  int age;
};

int main() {
  user u;
  u.id = 7;
  u.name = "Leland";
  u.age = 12;

  std::cout << "u.id = " << u.id << std::endl;
  std::cout << "u.name = " << u.name << std::endl;
  std::cout << "u.age = " << u.age << std::endl;

  return 0;
}
