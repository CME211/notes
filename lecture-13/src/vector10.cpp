#include <iostream>
#include <vector>

int main()
{
  std::vector<int> v1;
  v1.push_back(42);
  v1.push_back(-7);
  v1.push_back(19);

  std::vector<int> v2 = v1;
  v2[1] = 73; 

  for (unsigned int n = 0; n < v1.size(); n++) {
    std::cout << "v1[" << n << "] = " << v1[n] << std::endl;
  }
  for (unsigned int n = 0; n < v2.size(); n++) {
    std::cout << "v2[" << n << "] = " << v2[n] << std::endl;
  }
  return 0;
}
