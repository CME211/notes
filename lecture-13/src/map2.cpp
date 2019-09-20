#include <iostream>
#include <map>


// Topics covered in this example:
// 1. C++11 loops
// 2. auto type
// 3. Standard map: An ordered tree of pairs
//   - Similar in functionality to python dictionary
//   - Complexity of accessing map element ~> O(n)
// 4. Accessing map values by value and by reference
// 5. Variable names 'first' and 'second' denote the key and the value of a map element

int main()
{
  // Define a map 'dir' with characters as keys and strings as values
  std::map<char,std::string> dir;

  dir['A'] = std::string("south");
  dir['B'] = std::string("north");
  dir['C'] = std::string("east");
  dir['D'] = std::string("west");

  // Printing by value
  for (auto d : dir)
    std::cout << "d[" << d.first << "] = " << d.second << std::endl;
  std::cout << std::endl;

  // Printing by constant reference
  for (const auto& d : dir)
    {
      std::cout << "d[" << d.first << "] = " << d.second << std::endl;
    }

  return 0;
}
