#ifndef _CHECKING_H_
#define _CHECKING_H_
#include "Account.h"

class Checking : public Account {
public:
    bool withdraw(double cash);
    Checking(double balance);
};

#endif
