CXX := g++
CXXFLAGS := -std=c++11 -Wall -Wextra -Wconversion

stack4: stack4.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

stack5: stack5.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

pointer1: pointer1.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

pointer2: pointer2.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

increment: increment.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

func: func.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

pointer3: pointer3.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

pointer4: pointer4.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

pointer5: pointer5.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

new1: new1.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

new2: new2.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

new3: new3.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

new4: new4.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

new5: new5.cpp
	$(CXX) -g $(CXXFLAGS) $< -o $@

main1: main1.cpp MyVector1.cpp
	$(CXX) -g $(CXXFLAGS) $^ -o $@

main2: main2.cpp MyVector2.cpp
	$(CXX) -g $(CXXFLAGS) $^ -o $@

.PHONY: clean
clean:
	$(RM) stack4
	$(RM) stack5
	$(RM) pointer1
	$(RM) pointer2
	$(RM) pointer3
	$(RM) pointer4
	$(RM) pointer5
	$(RM) increment
	$(RM) func
	$(RM) new1
	$(RM) new2
	$(RM) new3
	$(RM) new4
	$(RM) new5
	$(RM) main1
	$(RM) main2
