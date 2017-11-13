#include <fstream>
#include <iostream>

#include "readnames.hpp"

// Opens file 'filename' and loads its content into a map.
std::map<std::string,std::tuple<double,double,int> > ReadNames(std::string filename)
{
  // Create file I/O stream
  std::ifstream f(filename);

  // Create map 'names'
  std::map<std::string,std::tuple<double,double,int> > names;

  std::string name;
  double perc1, perc2;
  int rank;
  // Read file entries and store them into the map 'names'
  while(f >> name >> perc1 >> perc2 >> rank) {
    names[name] = std::make_tuple(perc1, perc2, rank);
  }

  // Return map 'filename' by value
  return names;
}
