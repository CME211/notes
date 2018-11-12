#include <vector>
#include <iostream>

int main() {
  // declare vector of vectors
  std::vector< std::vector<double> > v;
  // add empty "second-level" vectors
  for (int i = 0; i < 3; i++) v.push_back(std::vector<double>());
  // add some data
  double n = 0.;
  for(unsigned int i = 0; i < 3; i++)
    for(unsigned int j = 0; j < 3; j++)
      v[i].push_back(n++);
      n++;
  // print
  std::cout << "sizeof(v): " << sizeof(v) << std::endl;
  for(unsigned int i = 0; i < 3; i++) {
    for(unsigned int j = 0; j < 3; j++) {
      std::cout << "v[" << i << "][" << j << "] = " << v[i][j] << std::endl;
    }
  }
}
