#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::string simplifyPath(std::string path) {
  std::string res, tmp;     
  std::vector<std::string> stk;    
  std::stringstream ss(path);     
  while(getline(ss,tmp,'/')) {         
    if (tmp == "" or tmp == ".")      continue;         
    if (tmp == ".." and !stk.empty()) stk.pop_back();         
    else if (tmp != "..")             stk.push_back(tmp);    
  }     
  for(auto str : stk) res += "/" + str;     
  return res.empty() ? "/" : res; 
}


int main(int argc, char *argv[]) {
    if (argc < 2) return 1;
    std::cout << simplifyPath(argv[1]) << std::endl;
}
