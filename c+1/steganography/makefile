CC=g++
APPS=encrypt decrypt
Flags=-Wall -std=c++11
all:$(APPS)

encrypt:ImageData.o encrypt.o
	$(CC) $(Flags) -o $@ $^
decrypt:ImageData.o decrypt.o
	$(CC) $(Flags) -o $@ $^
encrypt.o:encrypt.cpp
	$(CC) $(Flags) -c -o $@ $^
decrypt.o:decrypt.cpp
	$(CC) $(Flags) -c -o $@ $^
ImageData.o:ImageData.cpp
	$(CC) $(Flags) -c -o $@ $^

clean:
	rm -rf *.o