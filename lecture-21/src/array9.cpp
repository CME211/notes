#include <iostream>
#include <boost/multi_array.hpp>

int main() {
  boost::multi_array<double, 2> a(boost::extents[3][3]);

  double n = 0.;
  for (unsigned int i = 0; i < 3; i++) {
    for (unsigned int j = 0; j < 3; j++) {
      a[i][j] = n;
      n++;
    }
  }

  /* Setup b as a view into a subset of a. */
  typedef boost::multi_array<double, 2>::index_range index_range;
  auto b = a[boost::indices[index_range(1,3)][index_range(1,3)]];

  for (unsigned int i = 0; i < 2; i++) {
    for (unsigned int j = 0; j < 2; j++) {
      b[i][j] = -1.;
    }
  }

  for (unsigned int i = 0; i < 3; i++) {
    for (unsigned int j = 0; j < 3; j++) {
      std::cout << a[i][j] << std::endl;
    }
  }
  return 0;
}
