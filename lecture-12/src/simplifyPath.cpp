#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {
    std::string res, tmp;
    std::vector<std::string> stk;
    if (argc < 2) return 1;
    std::stringstream ss(argv[1]);
    while(getline(ss,tmp,'/')) {
        if (tmp == "" or tmp == ".")
            continue;
        if (tmp == ".." and !stk.empty())
            stk.pop_back();
        else if (tmp != "..")
            stk.push_back(tmp);
    }
    for(auto str : stk)
        res += "/" + str;
    std::cout << res << std::endl;
}
