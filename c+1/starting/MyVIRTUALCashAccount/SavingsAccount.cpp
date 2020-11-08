#include "SavingsAccount.h"
#include <iostream>



SavingsAccount::SavingsAccount(double balance, double rate)
    :Account(balance), rate(rate) {

}
std::ostream & SavingsAccount::print(std::ostream &os) {
    os << "Savings account balance is: " << balance << std::endl;
    os << "Current rate is " << rate;
    return os;
}
bool SavingsAccount::deposit(double cash) {
    if (cash < 0 || rate < 0) {
        return false;
    }
    balance += cash * (1 + rate);
    return true;

}

bool SavingsAccount::withdraw(double cash) {
    if (cash < 0 || balance - cash < 0) {
        return false;
    }
    balance -= cash;
    return true;
}
