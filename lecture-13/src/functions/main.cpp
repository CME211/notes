#include <iostream>
#include <string>
#include <vector>

#include "readnames.hpp"
#include "testname.hpp"

int main()
{
  // Read file and store its data in object 'names'.
  // Let compiler find the type of the object.
  auto names = ReadNames("../dist.female.first");

  // Create a vector of strings. 
  std::vector<std::string> tests;
  tests.push_back("LINDA");
  tests.push_back("PETER");
  tests.push_back("DOROTHY");

  // Check for each name in the vector if it is stored in object 'names'.
  // If the name is found in object 'names' print its rank, otherwise print zero.
  for(auto test : tests)
  {
    std::cout << test << " " << TestName(names, test) << std::endl;
  }

  return 0;
}
