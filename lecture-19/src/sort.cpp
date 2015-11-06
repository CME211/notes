#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
  std::vector<int> v;
  v.push_back(42);
  v.push_back(-7);
  v.push_back(19);
  v.push_back(73);
  v.push_back(0);

  std::sort(v.begin(), v.end());

  for(unsigned int n = 0; n < v.size(); n++)
    std::cout << "v[" << n << "] = " << v[n] << std::endl;

  return 0;
}
