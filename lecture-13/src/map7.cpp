#include <iostream>
#include <map>


// Method find() searches for the key provided in the argument and
// if it finds it, returns iterator to it. Otherwise returns iterator
// to end().
// See: http://www.cplusplus.com/reference/map/map/find/

int main() {
  std::map<char, std::string> dir;

  dir['A'] = std::string("north");
  dir['B'] = std::string("east");
  dir['C'] = std::string("south");
  dir['D'] = std::string("west");

  char key = 'C';
  //key = 'G';
  auto iter = dir.find(key);
  if (iter == dir.end()) {
    std::cout << "key " << key << " is not present" << std::endl;
  }
  else {
    std::cout << "key " << key << " is present" << std::endl;
    std::cout << "value is " << iter->second << std::endl;
  }

  return 0;
}
