#include <iostream>
#include <vector>

int main()
{
  std::vector<int> v;
  v.push_back(42);
  v.push_back(-7);
  v.push_back(19);

  std::cout << "v[-1] = " << v[-1] << std::endl;

  return 0;
}
