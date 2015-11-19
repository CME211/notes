#CXX := g++
CXX := clang++
CXXFLAGS := -std=c++11 -Wall -Wextra -Wconversion

map_assignment: map_assignment.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY: run
run: map_assignment
	./map_assignment

.PHONY: clean
clean:
	$(RM) map_assignment
