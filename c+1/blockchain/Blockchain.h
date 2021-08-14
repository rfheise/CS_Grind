#ifndef __BLOCKCHAIN__H
#define __BLOCKCHAIN__H
#include <string>
#include <iostream>
#include "Block.h"
using namespace std;
class Blockchain {
private:
    int size;
    int arrsize;
    Block **arr;
    static constexpr int defaultArrSize = 1;
    void resize();
public:
    void addBlock(string &&data);
    void addBlock(string &data);
    bool isValid();
    Block *operator[](int index);
    //makes block chain valid
    //remines all invalid blocks
    void mineChain();
    //updates previous hashes with most current value
    void updateHashes();
    Blockchain();
    ~Blockchain();
    friend ostream & operator<<(ostream& os, Blockchain &chain);
};

#endif