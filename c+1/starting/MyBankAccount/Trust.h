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
    bool deposit(double balance);
    bool withdraw(double cash);
};



#endif
