#include <iostream>

#include "testname.hpp"

// Function TestName takes two arguments -- a map 'names' and a string 'name'.
// The function tests if the 'name' is in the 'names', and if so it returns
// the 'name' rank, which is stored in 'names'.
double TestName(std::map<std::string,std::tuple<double,double,int>> names,
                std::string name)
{
  // Variable to store name rank
  int name_rank = 0;

  // The variable 'match' is a map iterator. Function 'find(mapKey)' returns
  // the iterator that points to the map entry with key value 'mapKey'
  auto match = names.find(name);

  // Check if the iterator returns end value (i.e. 'mapKey' is not in the map).
  // If not, read the name rank for the 'name'.
  if (match != names.end())
  {
    // The name rank is the third entry (index 2) in the tuple 'match->second'.
    // It is retrieved by calling std::get<2> function.
    name_rank = std::get<2>(match->second);
  }

  return name_rank;
}
