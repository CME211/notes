#include <iostream>
#include <sstream>

int main(int argc, char *argv[]) {
  // Setup a string stream to access the command line argument
  std::string arg = argv[1];
  std::stringstream ss;
  ss << arg;

  // Attempt to extract an integer from the string stream
  unsigned n = 0;
  if (ss >> n) {    // Test for extraction success!
    std::cout << "n = " << n << std::endl;
  } else {
    std::cerr << "ERROR: string stream extraction failed" << std::endl;
  }
  return 0;
}
