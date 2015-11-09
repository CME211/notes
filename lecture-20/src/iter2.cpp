#include <iostream>
#include <vector>

int main()
{
  std::vector<double> vec;

  vec.push_back(7);
  vec.push_back(11);
  vec.push_back(42);

  for (auto &v : vec)
    v++;

  for (auto v : vec)
    std::cout << v << std::endl;

  return 0;
}
