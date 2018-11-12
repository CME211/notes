#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
  std::vector<int> v {42, -7, 19, 73, 0};

  std::sort(v.begin(), v.end());

  for(unsigned int n = 0; n < v.size(); n++)
    std::cout << "v[" << n << "] = " << v[n] << std::endl;

  return 0;
}
