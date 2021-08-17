#ifndef __HASH__H
#define __HASH__H
typedef unsigned char BYTE;
#include "Block.h"
class Hash {
private:
    BYTE  *hash;
    //size of hash for using sha 256
    static constexpr int HASH_SIZE = 32;
    void hashWrapper(BYTE *data, int size);
public:
    //hashes data
    Hash(BYTE *data, int size);
    //hashes a block
    Hash(const Block& block);
    //copy constructor
    Hash(const Hash &copy);
    //deconstructor
    ~Hash();
};
#endif