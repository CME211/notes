#include <iostream>

class user {
  int id = 7;
 public:
  int getId(void) {
    return id;
  }
};

int main() {
  user u;
  std::cout << "u.getId() = " << u.getId() << std::endl;
  return 0;
}
