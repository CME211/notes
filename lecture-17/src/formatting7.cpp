#include <iomanip>
#include <iostream>

int main() {
  
  std::cout.fill('0');
  
  for(int n = 0; n < 10; n++) {
    std::cout << std::setw(2) << n << std::endl;
  }
  
  return 0;
}
