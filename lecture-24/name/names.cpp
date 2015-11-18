#include <fstream>
#include <iostream>
#include <string>
#include <tuple>

#include "names.hpp"

NameClassifier::NameClassifier(std::string file_female, std::string file_male) {
  // Read each of the files
  readData(file_female, female);
  readData(file_male, male);
}

void NameClassifier::readData(std::string file, namemap& names) {
  std::ifstream f(file);
  if (not f.is_open()) {
    std::cerr << "ERROR: Could not open file " << file << std::endl;
    exit(1);
  }

  std::string name;
  double perc1, perc2;
  unsigned int rank;
  while (f >> name >> perc1 >> perc2 >> rank) {
    names[name] = std::make_tuple(perc1, perc2, rank);
  }

  f.close();
}

double NameClassifier::classifyName(std::string name) {
  auto f = female.find(name);
  auto m = male.find(name);

  // name was not found
  if (f == female.end() and m == male.end()) return 0.5;

  // definitely male or female
  if (f == female.end()) return 0.;
  if (m == male.end()) return 1.;

  // somewhere in between
  return std::get<0>(f->second)/(std::get<0>(f->second) + std::get<0>(m->second)); 
}

namemap::size_type NameClassifier::getNumberNames(void) {
  return getNumberFemaleNames() + getNumberMaleNames();
}

namemap::size_type NameClassifier::getNumberFemaleNames(void) {
  return female.size();
}

namemap::size_type NameClassifier::getNumberMaleNames(void) {
  return male.size();
}
