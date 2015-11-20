#CXX := clang++
CXX := g++
CXXFLAGS := -std=c++11 -Wall -Wextra -Wconversion

# debugging
CXXFLAGS += -g

slda: slda.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY: run
run: slda
	./slda

.PHONY: clean
clean:
	$(RM) slda
	$(RM) -r slda.dSYM
