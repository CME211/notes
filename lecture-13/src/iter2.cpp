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

  // Creates a reference v to each element in vec and increments each element.
  for (auto& v : vec)
    ++v;

  // The original elements of the vector vec are incremented by one
  for (const auto& v : vec)
    std::cout << v << std::endl;

  return 0;
}
