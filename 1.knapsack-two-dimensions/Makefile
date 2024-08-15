CXXC = g++

CXXFLAGS = -std=c++11 -O3 -Wall

all: main

main: gen_supermarble.cpp
	$(CXX) $(CXXFLAGS) -o gen gen_supermarble.cpp -lm

.PHONY: clean
clean:
	rm -f main gen