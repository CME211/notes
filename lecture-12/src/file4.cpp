#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) {

  if (argc < 2) {
    std::cout << "Usage:" << std::endl;
    std::cout << "  " << argv[0] << " <filename>" << std::endl;
    return 0;
  }

  std::ifstream f;
  
  f.open(argv[1]);
  if (f.is_open()) {
    std::string line;
    while (getline(f, line)) {
      std::cout << line << std::endl;
    }
    f.close();
  }
  else {
    std::cerr << "ERROR: Failed to open file" << std::endl;
  }

  return 0;
}
