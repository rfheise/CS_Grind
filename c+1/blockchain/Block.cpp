#include "Block.h"
#include "sha256/sha256.h"
#include <stdlib.h>
#include <iostream>
#include <cstring>
using namespace std; 

//determines if the block is valid
bool Block::isValid() const{
    BYTE data[hashSize];
    getHash(data);
    return isValid(data);
}
//determines if a hash is valid
bool Block::isValid(const BYTE *hash) {
    // return !hash[0] && !hash[1];
    return !hash[0];
    // return !hash[0] && !hash[1] && !(hash[2] & 240);
}
string Block::getData() {
    return data;
}
//returns hash value
//converts inputed array to hash value of block
//returns original pointer
BYTE * Block::getHash(BYTE *arr) const{
    //put data into one string
    int bufferSize = nonceSize + data.size() + hashSize;
    char buffer[bufferSize];
    for (int i = 0; i < nonceSize; i++) {
        buffer[i]= nonce[i];
    }
    for (long unsigned int i = nonceSize; i < (nonceSize + data.size()); i++) {
        buffer[i] = data[i - nonceSize];
    }
    for (int i = nonceSize + data.size(); i < bufferSize; i++) {
        buffer[i] = prevHash[i - (nonceSize + data.size())];
    }
    string data(buffer, bufferSize);
    //hash data and return value
    sha256(data, arr);
    return arr;
}
//updates prev hash value
void Block::setPrevHash(const BYTE *arr) {
    for(int i = 0;  i < hashSize; i++) {
        prevHash[i] = arr[i];
    }
}
//creates a block
Block::Block(BYTE *prevHash, string data)
    :mined(false), prevHash(new BYTE[hashSize]), data(data) {
        for(int i = 0; i < hashSize; i++) {
            this -> prevHash[i] = prevHash[i];
        }
}

void Block::generateNonce() {
    if (mined) {
        delete [] nonce;
    }
    nonceSize = rand() % maxNonceSize;
    nonce = new BYTE[nonceSize];
    for (int i = 0; i < nonceSize; i++) {
        //store up to max char value
        nonce[i] = rand() % 256;
    }
}
//"mines block" makes it's hash valid
void Block::mine() {
    BYTE hash[hashSize];
    do {
        generateNonce();
        mined = true;
        getHash(hash);
    } while(!isValid(hash));
}
//frees memory used by block
Block::~Block() {
    delete[] prevHash;
    if (mined) {
        delete[] nonce;
    }
}
//returns string of hash in binary
string Block::binaryHash() const{
    unsigned char data[hashSize];
    getHash(data);
    int size = 256;
    char buff[size];
    for (int i = 0; i < hashSize; i++) {
        int start  = (1 << 7);
        for(int j = 7; j >= 0; j--) {
            buff[i*8 + (7 - j)] = ((data[i] & start) >> j) + '0';
            start >>= 1;
        }
    }
    cout << "here" << endl;
    return string(buff, size);
}
string Block::hexHash() const {
    BYTE hash[hashSize];
    getHash(hash);
    char buffer[hashSize * 2 + 1];
    buffer[hashSize * 2] = '\0';
    for (int i = 0; i < hashSize; i++) {
        sprintf(&(buffer[i * 2]),"%02x", (int)hash[i] & 0xff);
    }
    return string(buffer);
}
void Block::setData(string data) {
    this -> data = data;
}
ostream& operator<<(ostream &os, const Block &block) {
    if (block.mined) {
        os << "Nonce Size: " << block.nonceSize << endl;
        os << "Block Hash: " << block.hexHash() << endl;
        os << "Data in Block: " << block.data << endl;
    } else {
        os << "Block Not Mined" << endl;
    }
    return os;
}