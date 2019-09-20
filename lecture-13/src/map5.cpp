#include <iostream>
#include <map>

// Topics covered in this example:
// 1. Standard map: An ordered tree of pairs
//   - Similar in functionality to python dictionary
//   - Complexity of accessing map element ~> O(n)
// 2. Accessing map elements
//   - If nonexistant element is accessed by subscript, a new map entry is created
//   - If nonexistant element is accessed by method at(), an exception is thrown

int main()
{
  std::map<char, std::string> dir;

  dir['A'] = std::string("north");
  dir['B'] = std::string("east");
  dir['C'] = std::string("south");
  dir['D'] = std::string("west");

  // Map size = 4
  std::cout << "dir.size() = " << dir.size() << std::endl;

  // Throws an exception -- out of range
  std::cout << "dir[G] = "     << dir.at('G')     << std::endl;
  
  return 0;
}
