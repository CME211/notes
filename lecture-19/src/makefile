CXX := g++
#CXX := clang++
CXXFLAGS := -std=c++11 -Wall -Wextra -Wconversion -g -fsanitize=address

run-% : %
	./$<

.PHONY: clean
clean:
	$(RM) -r *.dSYM
