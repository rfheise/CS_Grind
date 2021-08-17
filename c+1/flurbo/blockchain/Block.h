#ifndef __BLOCK__H
#define __BLOCK__H
#include  <time.h>
#include "Hash.h"
#include "../transaction/Transaction.h"
class Block {
private:
    time_t timestamp;
    Hash hash;
    Hash prevHash;
    long nonce;
    Transaction *transactions;
    int transactionSize;
    //determines if transactions are valid
    bool transactionsValid();
public:
    //doubly linked list 
    Block *next;
    Block *prev;
    static const Hash difficulty;
    //constructor
    Block(time_t timestamp, const Hash &prevHash, long nonce,
        Transaction *transactions, int transactionSize, Block *prev);
    //calculates current hash value
    void calculateHash();
    //mines for hash below the current difficulty
    void mine();
    //determines if block is valid
    bool isValid();
    //gets prevHash
    Hash getPrevHash();
    //sets prevHash
    void setPrevHash();
    //gets nonce
    long getNonce();
    //gets timestamp
    time_t getTimeStamp();
    //gets transactions
    //stores size at address of integer passed in
    Transaction *getTransactions(int *size);
    //deconstructor
    ~Block();


    

};

#endif