#include <iostream>
#include "Checking.h"


bool Checking::withdraw(double cash) {
    if (cash < 0 || balance - cash - 1.5 < 0) {
        return false;
    }
    balance -= cash + 1.5;
    return true;
}

bool Checking::deposit(double cash) {
    if (cash < 0) {
        return false;
    }
    balance += cash;
    return true;
}

Checking::Checking(double balance)
    :Account(balance){

}

std::ostream & Checking::print(std::ostream &os) {
    os << "Checking ";
    return Account::print(os);
}
