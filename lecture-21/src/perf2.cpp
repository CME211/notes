#include <iostream>
#include <ctime>

// disable boost range checking
#define BOOST_DISABLE_ASSERTS
#include <boost/multi_array.hpp>

int main() {
  unsigned int nrows = 8192, ncols = 8192;
  boost::multi_array<double, 2> a(boost::extents[nrows][ncols]);

  for (unsigned int i = 0; i < nrows; i++) {
    for (unsigned int j = 0; j < ncols; j++) {
      a[i][j] = 1.0;
    }
  }
  
  auto t0 = std::clock();
  double sum = 0.;
  for (unsigned int i = 0; i < nrows; i++) {
    for (unsigned int j = 0; j < ncols; j++) {
      sum += a[i][j];
    }
  }
  auto t1 = std::clock();

  std::cout << " boost: sum = " << sum << ", time = "
            << double(t1-t0) / CLOCKS_PER_SEC
            << " seconds"<< std::endl;

  auto b = a.data();
  t0 = std::clock();
  sum = 0.;
  for (unsigned int n = 0; n < nrows*ncols; n++) {
    sum += b[n];
  }
  t1 = std::clock();
  std::cout << "direct: sum = " << sum << ", time = "
            << double(t1-t0) / CLOCKS_PER_SEC
            << " seconds"<< std::endl;
  return 0;
}
