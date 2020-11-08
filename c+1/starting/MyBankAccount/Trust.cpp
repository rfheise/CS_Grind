#include "Trust.h"
#include <string>

using std::string;


Trust::Trust(double balance, double rate, string name)
    :SavingsAccount(balance, rate), name(name), withdraws(0){

}
bool Trust::deposit(double balance) {
    if (balance >= 5000) {
        balance += 50;
    }
    return SavingsAccount::deposit(balance);
}
bool Trust::withdraw(double cash) {
    if (withdraws > 3) {
        return false;
    }
    withdraws ++;
    return SavingsAccount::withdraw(balance);
}
