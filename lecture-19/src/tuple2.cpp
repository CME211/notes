#include <iostream>
#include <fstream>
#include <tuple>
#include <vector>

int main() {
  std::ifstream f;
  std::vector<std::tuple<std::string,float,float,int>> names;

  f.open("dist.female.first");
  if (f.is_open()) {
    std::string name;
    double perc1, perc2;
    int rank;
    while (f >> name >> perc1 >> perc2 >> rank) {
      names.emplace_back(name, perc1, perc2, rank);
    }
    f.close();
  }
  else {
    std::cerr << "ERROR: Failed to open file" << std::endl;
  }

  for(unsigned int n = 0; n < names.size(); n++) {
    std::cout << std::get<0>(names[n]) << " " << std::get<1>(names[n]) << std::endl;
  }

  return 0;
}
