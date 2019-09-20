#include <iostream>
#include <string>

int main() {
  std::string n = "Hi";
  std::cout << "n = " << n << std::endl;

  {
    int n = 5;
    {
      std::cout << "n = " << n << std::endl;
    }
  }

  return 0;
}
