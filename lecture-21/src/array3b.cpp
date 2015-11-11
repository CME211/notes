#include <iostream>
#define BOOST_DISABLE_ASSERTS
#include <boost/multi_array.hpp>

int main() {
  boost::multi_array<double, 2> a(boost::extents[3][3]);
  a[3][3] = 1.;
  return 0;
}
