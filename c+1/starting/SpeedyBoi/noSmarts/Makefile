CXX = g++
CXXFLAGS = -Wall -g -std=c++17

main: main.o Hash.o Node.o
	$(CXX) $(CXXFLAGS) -o main main.o Hash.o Node.o

main.o: main.cpp Hash.h Node.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Node.o: Node.h
	$(CXX) $(CXXFLAGS) -c -o Node.o Node.h
Hash.o: Hash.h Node.h
	$(CXX) $(CXXFLAGS) -c -o Hash.o Hash.h
