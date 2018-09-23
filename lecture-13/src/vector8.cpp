#include <iostream>
#include <vector>

int main()
{
  std::vector<int> v;
  v.push_back(42);
  v.push_back(-7);
  v.push_back(19);

  //  Declare an iterator
  std::vector<int>::iterator iter;

  // Set iterator to start of vector

  iter = v.begin();

  // Advance iterator by two positions
  iter += 2;

  // Use iterator to insert a new value into the vector
  v.insert(iter, 73);

  for(unsigned int n = 0; n < v.size(); n++)
    std::cout << "v[" << n << "] = " << v[n] << std::endl;

  return 0;
}
