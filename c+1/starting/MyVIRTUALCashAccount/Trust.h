#ifndef _TRUST_H_
#define _TRUST_H_
#include <string>
#include "SavingsAccount.h"

using std::string;

class Trust :public SavingsAccount {
protected:
    int withdraws;
    string name;
private:
    static constexpr const double newbalance = 0;
public:
    Trust(double balance = newbalance, double rate = newbalance, string name = "Unknown");
    virtual bool deposit(double balance) override;
    virtual bool withdraw(double cash) override;
    virtual std::ostream & print(std::ostream &os) override;
};



#endif
