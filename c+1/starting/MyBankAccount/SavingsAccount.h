#ifndef _SAVINGSACCOUNT_H_
#define  _SAVINGSACCOUNT_H_
#include "Account.h"
#include <ostream>

class SavingsAccount: public Account {
    friend std::ostream & operator<<(std::ostream &os, SavingsAccount & savings);
private:
    static constexpr double newbalance = 0;
    static constexpr const double newrate = 0;
protected:
    double rate;
public:
    bool deposit(double cash);
    SavingsAccount(double balance = newbalance, double rate = newrate);
};


#endif
