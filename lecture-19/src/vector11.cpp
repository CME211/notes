#include <iostream>
#include <fstream>
#include <vector>

std::vector<int> ReadNumbers(std::string filename) {
  std::vector<int> v;
  std::ifstream f(filename.c_str());
  if (f.is_open()) {
    int val;
    while (f >> val) v.push_back(val);
    f.close();
  }
  return v;
}

int main() {
  std::vector<int> v = ReadNumbers("numbers.txt");

  for(unsigned int n = 0; n < v.size(); n++)
    std::cout << "v[" << n << "] = " << v[n] << std::endl;

  return 0;
}
