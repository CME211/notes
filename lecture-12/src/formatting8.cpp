#include <iostream>
#include <fstream>

int main() {
  double a = 2., b = 3.14;
  int c = 4;
  
  std::ofstream f("formatting.txt");
  f.setf(std::ios::showpoint);
  
  f << "a = " << a << std::endl;
  f << "b = " << b << std::endl;
  f << "c = " << c << std::endl;
  
  f.close();
  
  return 0;
}
