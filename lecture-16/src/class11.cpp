#include <iostream>

class user {
  int id;
 public:
  user(int id) { this->id = id; }
  int getId(void) { return id; }
};

int main() {
  user u;
  std::cout << "u.getId() = " << u.getId() << std::endl;
  return 0;
}
