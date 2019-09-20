#include <iostream>

int main(int argc, char* argv[]) {
        if (argc < 2) return 1;
        unsigned n = std::stoi(argv[1]);
        std::cout << "You input n = " << n << std::endl;
}
