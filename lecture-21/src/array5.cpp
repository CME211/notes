#include <iostream>
#include <boost/multi_array.hpp>

int main() {
  boost::multi_array<double, 2> a(boost::extents[3][3]);
  boost::multi_array<double, 2> b(boost::extents[3][3]);

  for (unsigned int i = 0; i < 3; i++) {
    for (unsigned int j = 0; j < 3; j++) {
      a[i][j] = 1.;
      b[i][j] = 2.;
    }
  }

  std::cout << "a == b: " << (a == b) << std::endl;
  std::cout << "a < b: " << (a < b) << std::endl;
  std::cout << "a > b: " << (a > b) << std::endl;

  return 0;
}
