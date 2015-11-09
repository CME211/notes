#include <iostream>

#include "testname.hpp"

double TestName(std::map<std::string,std::tuple<double,double,int>> names,
                std::string name)
{
  double percentage = 0.;

  auto match = names.find(name);
  if (match != names.end())
  {
    percentage = std::get<0>(match->second);
  }

  return percentage;
}
