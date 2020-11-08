#ifndef _SAVINGSACCOUNT_H_
#define  _SAVINGSACCOUNT_H_
#include "Account.h"
#include <ostream>

class SavingsAccount: public Account {
private:
    static constexpr double newbalance = 0;
    static constexpr const double newrate = 0;
protected:
    double rate;
public:
    virtual bool deposit(double cash) override;
    virtual bool withdraw(double cash) override;
    virtual std::ostream & print(std::ostream &os) override;
    SavingsAccount(double balance = newbalance, double rate = newrate);
};


#endif
