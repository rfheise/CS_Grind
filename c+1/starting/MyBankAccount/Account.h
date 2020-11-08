#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <ostream>

using std::ostream;

class Account {
    friend ostream & operator<<(ostream &os, Account &a);

public:
    Account(double balance = newbalance);
    double getBalance();
    void setBalance(double balance);
    bool deposit(double cash);
    bool withdraw(double cash);
    Account & operator+=(const Account& val);
    Account & operator-=(const Account& val);

protected:
    double balance;
private:
    static constexpr const double newbalance = 0;
};

#endif
