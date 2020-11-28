#include "Checking.h"
#include "Account.h"
#include "InsufficientFundsException.h"
#include "IllegalBalanceException.h"
#include <string>

using namespace std;

Checking::Checking(const double balance, const char *name)
    :Account(balance, name) {

}

void Checking::deposit(double ammount) {
    if (ammount < 0) {
        throw IllegalBalanceException();
    }
    balance += ammount;
}

void Checking::withdraw(double ammount) {
     if (balance - ammount < 0) {
        throw InsufficientFundsException();
    }
    balance -= ammount;
}

string Checking::print() {
    return "Hello " + name + "'s" + " your balance is " + std::to_string(balance);
}