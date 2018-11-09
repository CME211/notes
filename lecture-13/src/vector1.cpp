#include <iostream>
#include <vector>

int main()
{
  std::vector<int> v(3);
  v[0] = 6;
  v[1] = 5;
  v[2] = 7;

  std::cout << "v.size() = " << v.size() << std::endl;

  if (v.empty())
    std::cout << "v is empty" << std::endl;
  else
    std::cout << "v is not empty" << std::endl;

  v.push_back(42);

  std::cout << "v.size() = " << v.size() << std::endl;

  if (v.empty())
    std::cout << "v is empty" << std::endl;
  else
    std::cout << "v is not empty" << std::endl;

  return 0;
}
