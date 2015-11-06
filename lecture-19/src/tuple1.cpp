#include <iostream>
#include <string>
#include <tuple>

int main()
{
  std::string h = "Hello";
  int a = 42;

  auto t = std::make_tuple(h, a);

  std::cout << "t[0] = " << std::get<0>(t) << std::endl;
  std::cout << "t[1] = " << std::get<1>(t) << std::endl;

  std::get<1>(t) = 19;

  std::cout << "t[1] = " << std::get<1>(t) << std::endl;

  return 0;
}
