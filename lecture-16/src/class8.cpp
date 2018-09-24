#include <iostream>

class user {
  int id = 1;
 public:
  int getId(void) { return id; }
  void setId(int id_) { id = id_; }
};

int main()
{
  user u;
  u.setId(7);
  std::cout << "u.getId() = " << u.getId() << std::endl;
  u.setId(42);
  std::cout << "u.getId() = " << u.getId() << std::endl;
  return 0;
}
