#ifndef _CHECKING_H_
#define _CHECKING_H_
#include "Account.h"
#include <iostream>

class Checking : public Account {
public:
    virtual bool withdraw(double cash) override;
    virtual bool deposit(double cash) override;
    virtual std::ostream & print(std::ostream &os) override;
    Checking(double balance);
};

#endif
