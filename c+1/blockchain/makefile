comp=g++
flags= -std=c++17 -Wall
generic= $(comp) $(flags) -o $@ $^
apps= hash block blockchain blockchainTest
sha256=sha256/sha256.o
all:$(apps)

hash: $(sha256) hashTest.o
	$(generic)
block: $(sha256) blockTest.o Block.o
	$(generic)
blockchain: $(sha256) blockchain.o Block.o Blockchain.o
	$(generic)
blockchainTest: $(sha256) blockchainTest.o Block.o Blockchain.o
	$(generic)
%.o:%.cpp
	$(generic) -c

.PHONY clean:
	rm -rf $(apps) sha256/*.o *.o