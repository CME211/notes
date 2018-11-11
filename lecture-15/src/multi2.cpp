#include <iostream>
#include <vector>

int main() {
  unsigned int nrows = 3, ncols = 3;
  std::vector<double> a;
  a.resize(nrows*ncols);

  double n = 0.;
  for(unsigned int i = 0; i < nrows; i++)
    for(unsigned int j = 0; j < ncols; j++)
      a[i*ncols + j] = n++; // manual indexing into "multi-dimensional array"

  for(unsigned int i = 0; i < nrows*ncols; i++)
    std::cout << "a[" << i << "] = " << a[i] << std::endl;
}
