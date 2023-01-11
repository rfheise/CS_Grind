CC=g++
APPS=encrypt decrypt
Flags=-Wall -std=c++11
all:$(APPS)


encrypt:ImageData.o encrypt.o
	$(CC) $(Flags) -o $@ $^
decrypt:ImageData.o decrypt.o
	$(CC) $(Flags) -o $@ $^
%.o: %.cpp
	$(CC) -c $(Flags) -o $@ $^

.PHONY:clean
clean:
	rm -rf *.o
