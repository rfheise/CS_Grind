CC=g++
flags=-Wall -O3 -std=c++17
oflags=$(flags) -c 
Apps=spillchick

all:$(Apps)

spillchick:Hash.o Node.o main.o
	$(CC) $(flags) -o $@ $^
Hash.o:Hash.h 
	$(CC) $(flags) -o $@ $^
Node.o:Node.h
	$(CC) $(flags) -o $@ $^ 
main.o:main.cpp 
	$(CC) $(flags) -o $@ $^

clean:
	rm -rf *.o