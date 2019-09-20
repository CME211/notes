#include <iostream>
#include <string>
#include <vector>

#include "names.hpp"

int main(int argc, char* argv[]) {
  std::string female_file = "dist.female.first";
  std::string male_file = "dist.male.first";
  if (argc == 3) {
    female_file = argv[1];
    male_file = argv[2];
  }

  auto classifier = NameClassifier(female_file,male_file);
  std::cout << "There are " << classifier.getNumberNames();
  std::cout << " names in our reference data." << std::endl;

  std::vector<std::string> testdata;
  testdata.push_back("PETER");
  testdata.push_back("LOIS");
  testdata.push_back("STEWIE");
  testdata.push_back("BRIAN");
  testdata.push_back("MEG");
  testdata.push_back("CHRIS");

  for (auto& name : testdata) {
    std::cout << name << ": " << classifier.classifyName(name) << std::endl;
  }
  
  return 0;
}
