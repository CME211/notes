#include <iostream>
#include <vector>

int main() {
  std::vector<int> a;
  for (int i = 0; i < 10; i++)
      a.push_back(i);
  std::cout << "sizeof(a)  : " << sizeof(a)   << std::endl;
  std::cout << "sizeof(int): " << sizeof(int) << std::endl;
  std::cout << "memory location of    a : " << &a << std::endl;
  std::cout << "memory location of data : " << a.data() << std::endl;
  std::cout << "memory location of a[0] : " << &a[0] << std::endl;  // Postfix operators bind tighter.
  std::cout << "memory location of a[1] : " << &a[1] << std::endl;
  return 0;
}
