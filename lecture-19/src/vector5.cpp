#include <iostream>
#include <vector>

int main()
{
  std::vector<int> v;
  v.push_back(42);
  v.push_back(-7);
  v.push_back(19);

  std::cout << "v.at(1) = " << v.at(1) << std::endl;
  std::cout << "v.at(3) = " << v.at(3) << std::endl;

  return 0;
}
