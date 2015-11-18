CXX := g++
CXXFLAGS := -std=c++11 -Wall -Wextra -Wconversion

main: main.cpp names.cpp names.hpp
	$(CXX) $(CXXFLAGS) main.cpp names.cpp -o $@

.PHONY: run
run: main
	./main

.PHONY: clean
clean:
	$(RM) main
