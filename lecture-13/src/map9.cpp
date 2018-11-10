#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <tuple>

// Topics covered in this example:
// 1. Standard map: An ordered tree of pairs
// 2. Tuples
// 3. Accessing tuple elements using std::get<>
// 4. File stream I/O
// 5. C++11 loops


int main() {
  // Open file and check if successful, print error message if it fails
  std::ifstream f("../dist.female.first");
  if (not f.good()) {
    std::cerr << "ERROR: Failed to open file" << std::endl;
    return 1;
  }

  // Create map 'names'
  std::map<std::string, std::tuple<double, double, int> > names;

  // Load file entries into the map
  std::string name;
  double perc1, perc2;
  int rank;
  while(f >> name >> perc1 >> perc2 >> rank) {
    names[name] = std::make_tuple(perc1, perc2, rank);
  }

  // Read from the map and print on std output
  // Method std::get<0>() gets 0th element of the tuple
  // The template parameter <0> must be a literal!
  for(const auto& data : names) {
    std::cout << data.first << " " << std::get<2>(data.second) << std::endl;
  }

  return 0;
}
