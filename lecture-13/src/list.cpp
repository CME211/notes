#include <iostream>
#include <list>

int main()
{
  std::list<int> l;
  l.push_back(42);
  l.push_back(17);
  l.push_back(9);

  auto it = l.begin();
  advance(it, 1);
  l.erase(it);

  for (auto val : l)
    std::cout << val << std::endl;

  return 0;
}
