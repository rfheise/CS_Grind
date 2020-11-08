#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <ostream>
#include "Printer.h"
using std::ostream;

class Account : public Printer {
public:
    double getBalance();
    void setBalance(double balance);
    virtual bool deposit(double cash) = 0;
    virtual bool withdraw(double cash) = 0;
    Account(double balance);
    virtual ~Account() = default;
    virtual ostream & print(ostream &os);
protected:
    double balance;
private:
    static constexpr const double newbalance = 0;
};

#endif
