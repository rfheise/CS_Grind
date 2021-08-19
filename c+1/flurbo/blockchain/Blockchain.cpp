#ifndef __BLOCKCHAIN__H
#define __BLOCKCHAIN__H
#include "Block.h"
#include "Hash.h"
#include "../mempool/Mempool.h"
#include "../transaction/User.h"
class Blockchain {
private:
    //pointer to root node
    Block *head;
    //pointer to tail node
    Block *tail;
    //number of nodes in the list
    int size;
    //chain mempool
    Mempool pool;
    //blockchain "miner"
    User user;
public:
    //chain constructor
    Blockchain();
    //mines a block with specified data and adds it to chain
    void mineBlock();
    //adds a block and then mines it
    void mineBlock(const Block& block);
    //adds a block to the chain
    void addBlock(const Block& block);
    //determines if blockchain is valid
    bool isValid();
    //chain deconstructor
    ~Blockchain();
};

#endif