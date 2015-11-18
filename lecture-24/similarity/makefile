CXX := g++
#CXX := clang++
CXXFLAGS := -std=c++11 -O3 -Wall -Wextra -Wconversion

similarity: similarity.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY: run
run: similarity
	python similarity.py u.data sim_cpy.txt
	pypy similarity.py u.data sim_pypy.txt
	./similarity u.data sim_cpp.txt

.PHONY: clean
clean:
	$(RM) similarity
	$(RM) sim_*.txt
