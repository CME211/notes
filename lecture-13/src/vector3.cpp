#include <iostream>
#include <vector>

int main()
{
  std::vector<int> v(3);
  v[0] = 42;
  v[1] = -7;
  v[2] = 19;

  for(unsigned int n = 0; n < v.size(); n++)
    std::cout << "v[" << n << "] = " << v[n] << std::endl;

  return 0;
}
