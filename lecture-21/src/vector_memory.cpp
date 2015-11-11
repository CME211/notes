#include <iostream>
#include <vector>

int main() {
  std::vector<int> a;
  for (int i = 0; i < 10; i++) {
    a.push_back(i);
  }
  std::cout << "sizeof(a): " << sizeof(a) << std::endl;
  std::cout << "    memory location of a: " << &a << std::endl;
  std::cout << " memory location of data: " << a.data() << std::endl;
  std::cout << "difference in memory loc: "
            << double((int*)&a-a.data()) / 1024 / 1024 / 1024 
            << " GB" << std::endl;
  return 0;
}
