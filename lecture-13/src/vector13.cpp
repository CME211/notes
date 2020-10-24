#include <iostream>
#include <vector>

void increment(std::vector<int>& v) 
{
  for (unsigned int n = 0; n < v.size(); n++) {
    v[n]++;
    std::cout << "v[" << n << "] = " << v[n] << std::endl;
  }
}

void print(std::vector<int> const& v) 
{
  // Item assignment not supported for a const object!
  // v[0] = 12;
  for (unsigned int n = 0; n < v.size(); n++) {
    std::cout << "v[" << n << "] = " << v[n] << std::endl;
  }
}

int main() 
{
  std::vector<int> v;
  v.push_back(42);
  v.push_back(-7);
  v.push_back(19);

  increment(v);
  print(v);

  return 0;
}


