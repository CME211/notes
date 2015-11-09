#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <string>

std::set<std::string> ReadNames(std::string filename)
{
  std::set<std::string> names;

  std::ifstream f(filename);
  if (not f.is_open())
  {
    std::cerr << "ERROR: Could not read file " << filename << std::endl;
    return names;
  }

  std::string name;
  double perc1, perc2;
  int rank;
  while (f >> name >> perc1 >> perc2 >> rank)
  {
    names.insert(name);
  }
  f.close();

  return names;
}

int main()
{
  auto fnames = ReadNames("dist.female.first");
  auto mnames = ReadNames("dist.male.first");

  std::set<std::string> common;

  std::set_intersection(fnames.begin(), fnames.end(), mnames.begin(), mnames.end(),
                        std::inserter(common, common.begin()));

  std::cout << fnames.size() << " female names" << std::endl;
  std::cout << mnames.size() << " male names" << std::endl;
  std::cout << common.size() << " common names" << std::endl;

  return 0;
}
