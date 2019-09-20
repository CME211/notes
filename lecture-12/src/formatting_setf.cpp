#include<iostream>
#include <iomanip>

int main() {
        std::cout.setf(std::ios_base::dec);
        std::cout << "The number 42 in decimal: " << 42 << std::endl;
        std::cout.setf(std::ios_base::oct, std::ios_base::basefield);
        std::cout << "The number 42 in octal:   " << 42 << std::endl;
        std::cout.setf(std::ios_base::hex, std::ios_base::basefield);
        std::cout << "The number 42 in hex:     " << 42 << std::endl;
}
