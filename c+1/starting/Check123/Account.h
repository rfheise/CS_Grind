#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <string>
#include <iostream>
#include "Printable.h"

using namespace std;

class Account : public Printable {
private:
    static const constexpr char * namestr = "John Doe";
    static const constexpr double balancestr = 0;
public:
    Account(const double balance =  balancestr,const char * name = namestr);
    virtual ~Account() = default;
    virtual void withdraw(double ammount) = 0;
    virtual void deposit(double ammount) = 0;
protected:
    double balance;
    string name;
};

#endif