#include <iostream>
#include <vector>

// Topics covered in this example:
// 1. C++11 loops
// 2. auto type
// 3. Passing by copy vs. passing by reference

int main()
{
  std::vector<double> vec;

  vec.push_back(7);
  vec.push_back(11);
  vec.push_back(42);

  // Creates a copy v for each element in vec and increments the copy
  for (auto v : vec)
    ++v;

  // The original elements of the vector vec are unchanged
  for (auto v : vec)
    std::cout << v << std::endl;

  return 0;
}
