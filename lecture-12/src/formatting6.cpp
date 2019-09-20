#include <iostream>

int main() {
  std::cout << "Minimum Field width...currently set to " <<  std::cout.width() << '\n';
  std::cout << "        10        20        30\n";  
  std::cout << "         ^         ^         ^\n";
  std::cout << "         |         |         |\n";
  std::cout << "123456789-123456789-123456789|\n";
  std::cout << 12.345 << std::endl;
  std::cout.width(15);
  std::cout << 12.345 << std::endl;
  std::cout.width(30);
  std::cout << 12.345 << std::endl;
}
