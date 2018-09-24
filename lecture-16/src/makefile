# files
SRC := $(wildcard ./*.cpp)
OBJ := $(patsubst %.cpp,%.o,$(SRC))
DEP := $(patsubst %.cpp,%.d,$(SRC))

# compiler
CXX := clang++
CXXFLAGS := -std=c++11 -Wall -Wextra -Wconversion

# load dependency files if they exist
-include $(DEP)

class1: class1.o
	$(CXX) -o $@ $^

class2: class2.o
	$(CXX) -o $@ $^

struct1: struct1.o
	$(CXX) -o $@ $^

class3: class3.o
	$(CXX) -o $@ $^

class6: class6.o
	$(CXX) -o $@ $^

class7: class7.o
	$(CXX) -o $@ $^

class8: class8.o
	$(CXX) -o $@ $^

class9: class9.o
	$(CXX) -o $@ $^

class10: class10.o
	$(CXX) -o $@ $^
	./$@

class11: class11.o
	$(CXX) -o $@ $^

circle1: circle1.o
	$(CXX) -o $@ $^
	./circle1

main2: main2.o circle2.o
	$(CXX) -o $@ $^
	./main2

container: container.o circle3a.o circle3b.o
	$(CXX) -o $@ $^
	./container

# rule to build all object files
.PHONY: all
all: $(OBJ)

# pattern rule to generate dependency files and compile object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -M -o $(patsubst %.o,%.d,$@) $<
	$(CXX) $(CXXFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	$(RM) $(OBJ) $(DEP)
	$(RM) circle1 class1 class10 class3 class6 class7 class8
	$(RM) class9 container main2 struct1 main3

# print helper for debugging
print-%:
	@echo $* := $($*)
