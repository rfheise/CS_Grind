#include "Blockchain.h"
#include "Block.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
void Blockchain::resize() {
    Block **newArr = new Block*[size * 2];
    for(int i = 0; i < arrsize; i++) {
        newArr[i] = arr[i];
    }
    arrsize = size * 2;
    delete[] arr;
    arr = newArr;
}
//add block for r value string
void Blockchain::addBlock(string &&data) {
    addBlock(data);
}
//adds a block to the blockchain
void Blockchain::addBlock(string &data) {
    if (size == arrsize) {
        resize();
    }
    BYTE prevHash[Block::hashSize] = {0};
    //set prevHash if it exists
    if (size > 0) {
        arr[size - 1] -> getHash(prevHash);
    } 
    //create a new block to add
    arr[size] = new Block(prevHash, data);
    arr[size] -> mine();
    cout << "Block mined successfully" << endl;
    cout << *arr[size];
    cout << "Blockchain still valid: " << (isValid() ? "true" : "false") << endl << endl;
    size++;
}
//determines if blockchain is valid
bool Blockchain::isValid() {
    updateHashes();
    for(int i = 0; i < size; i++) {
        if (!(arr[i] -> isValid())) {
            return false;
        }
    }
    return true;
}
//indexs blockchain
Block * Blockchain::operator[](int index) {
    return arr[index];
}
//updates previous hashes with most current value
void Blockchain::updateHashes() {
    BYTE prevHash[Block::hashSize] = {0};
    for(int i = 0; i < size; i++) {
        arr[i] -> setPrevHash(prevHash);
        arr[i] -> getHash(prevHash);
    }
}
//block chain constructor
Blockchain::Blockchain() 
    :size(0), arrsize(defaultArrSize), arr(new Block*[arrsize]){
        //seed rand with current time
        srand(time(nullptr));
        rand();
}
void Blockchain::mineChain() {
    BYTE prevHash[Block::hashSize] = {0};
    cout << "Re-mining chain" << endl;
    for(int i = 0; i < size; i++) {
        //update prevhash to be that of prev chain
        arr[i] -> setPrevHash(prevHash);
        if (!(arr[i] -> isValid())) {
            arr[i] -> mine();
        }
        cout << "Successfully re-mined chain #" << i + 1 << endl;
        arr[i] -> getHash(prevHash);
    }
    cout << "Chain successfully re-mined" << endl;
}
//<< overloaded operator for blockchain
ostream & operator<<(ostream& os, Blockchain &chain) {
    chain.updateHashes();
    for(int i = 0; i < chain.size; i++) {
        Block *block = chain[i];
        os << "Block #" << i + 1 << " with Data: " << block -> getData() << " Block Valid: "; 
        os << (block -> isValid() ? "true" : "false") << endl;
    }
    cout << "Blockchain size: " << chain.size << endl;
    cout << "Blockchain valid: " << (chain.isValid() ? "true" : "false") << endl;
    return os;
}
//block chain deconstructor
Blockchain::~Blockchain() {
    delete[] arr;
}