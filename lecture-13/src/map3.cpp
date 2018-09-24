#include <iostream>
#include <map>


// Topics covered in this example:
// 1. Standard map: An ordered tree of pairs
//   - Similar in functionality to python dictionary
//   - Complexity of accessing map element ~> O(n)
// 2. Map iterators
// 3. begin() and end() methods
// 4. Dereferencing pointers to 'first' and 'second' components of a map element.

int main()
{
  // Define a map 'dir' with characters as keys and strings as values
  std::map<char,std::string> dir;

  dir['A'] = std::string("south");
  dir['B'] = std::string("north");
  dir['C'] = std::string("east");
  dir['D'] = std::string("west");

  // C++03 standard map iteration
  // This is more cumbersome, but shows better what is going inside the loop.
  for (std::map<char,std::string>::iterator i = dir.begin(); i != dir.end(); i++)
    std::cout << "d[" << i->first << "] = " << i->second << std::endl;

  return 0;
}
