#ifndef _CHECKING_H_
#define _CHECKING_H_

#include "Account.h"
#include <string>

class Checking : public Account {
public:
    virtual void withdraw(double ammount) override;
    virtual void deposit(double ammount) override;
    Checking(double balance, const char * name);
    virtual std::string print() override;

};


#endif