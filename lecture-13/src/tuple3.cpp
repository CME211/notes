#include <iostream>
#include <fstream>
#include <tuple>
#include <vector>

int main() {
  std::ifstream f;
  std::vector<std::tuple<int,int,int,int>> data;

  f.open("u.data");
  if (f.is_open()) {
    int uid, mid, rating, time;
    while (f >> uid >> mid >> rating >> time) {
      data.emplace_back(uid, mid, rating, time);
    }
    f.close();
  }
  else {
    std::cerr << "ERROR: Failed to open file" << std::endl;
  }

  for (auto d : data) {
    std::cout << std::get<0>(d) << " " << std::get<1>(d);
    std::cout << " " << std::get<2>(d) << std::endl;
  }

  return 0;
}
