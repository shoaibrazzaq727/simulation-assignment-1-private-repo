CXX = g++
CXXFLAGS = -std=c++11

all: build run

build:
	$(CXX) $(CXXFLAGS) main.cpp -o simulation

run:
	./simulation

clean:
	rm simulation

