#include "Account.h"
#include <iostream>

using std::cout;
using std::endl;


//
double Account::getBalance() {
    return balance;
}
//
// Account & Account::operator+=(const Account& val) {
//     balance += val.balance;
//     return *this;
// }
// Account & Account::operator-=(const Account& val) {
//     balance -= val.balance;
//     return *this;
// }
//
// ostream & operator<<(ostream &os, Account &acc) {
//     return acc.print(os);
// }

ostream & Account::print(ostream &os)  {
    os << "Account Balance is: " << balance;
    return os;
}
//
// bool Account::deposit(double cash) {
//     if (cash < 0) {
//         return false;
//     }
//     (*this) += cash;
//     return true;
// }
// bool Account::withdraw(double cash) {
//     if (balance - cash < 0) {
//         return false;
//     }
//     (*this) -= cash;
//     return true;
// }
//

Account::Account(double balance)
    :balance(balance) {

}
//
void Account::setBalance(double balance) {
    this -> balance = balance;
}
