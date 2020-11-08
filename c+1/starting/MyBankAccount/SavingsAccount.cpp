#include "SavingsAccount.h"
#include <iostream>


std::ostream & operator<<(std::ostream &os, SavingsAccount & savings) {
    os << "Savings Account Balance is: " << savings.balance <<" " <<savings.rate;
    return os;
}

SavingsAccount::SavingsAccount(double balance, double rate)
    :Account(balance), rate(rate) {

}

bool SavingsAccount::deposit(double cash) {
    if (cash < 0 || rate < 0) {
        return false;
    }
    (*this) += cash * (1 + rate);
    return true;

}
