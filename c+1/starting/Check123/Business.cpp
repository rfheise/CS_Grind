#include "Checking.h"
#include "Business.h"
#include <iostream>
#include "IllegalBalanceException.h"
#include <string>

using namespace std;

void Business::deposit(double ammount) {
    ammount = ammount * interest + ammount;
    Checking::deposit(ammount);
}

Business::Business(const double balance, const char *name, const double interest) 
    :Checking(balance, name), interest(interest){
    
}

std::string Business::print() {
    return Checking::print() + " and your interest is " + to_string(interest);
}