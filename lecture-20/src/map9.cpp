#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <tuple>

int main() {
  std::ifstream f("dist.female.first");
  if (not f.good()) {
    std::cerr << "ERROR: Failed to open file" << std::endl;
    return 1;
  }

  std::map<std::string,std::tuple<double,double,int>> names;

  std::string name;
  double perc1, perc2;
  int rank;
  while(f >> name >> perc1 >> perc2 >> rank) {
    names[name] = std::make_tuple(perc1, perc2, rank);
  }

  for(auto &data : names) {
    std::cout << data.first << " " << std::get<0>(data.second) << std::endl;
  }

  return 0;
}
