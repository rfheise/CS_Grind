#ifndef __TRANSACTION__H
#define __TRANSACTION__H
#include "../blockchain/Hash.h"
class Transaction {
private:

public:
    void generateSignature();
    Transaction();
};

#endif