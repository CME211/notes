#include <iostream>

class user {
  // data member initialization is a C++11 feature
  int id = 7;
  int getId(void) {
    return id;
  }
};

int main() {
  user u;
  std::cout << "u.getId() = " << u.getId() << std::endl;
  return 0;
}
