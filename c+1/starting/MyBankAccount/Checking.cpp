#include <iostream>
#include "Checking.h"

bool Checking::withdraw(double cash) {
    if (cash < 0 || balance - cash - 1.5 < 0) {
        return false;
    }
    (*this) -= cash + 1.5;
    return true;
}

Checking::Checking(double balance)
    :Account(balance){
        
}
