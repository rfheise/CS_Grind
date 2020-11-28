#include "IllegalBalanceException.h"
#include "Checking.h"
#include "Account.h"
#include "InsufficientFundsException.h"
#include "Business.h"
#include <iostream>

using namespace std;

int main(void) {
    try {
        Business b = Business(0, "epic sauce", .5);
        b.deposit(0);
        b.withdraw(25);
        cout << b << endl;
    } catch (IllegalBalanceException &e) {
        cout << "Error";
        cout << e.what() << endl;
    } catch (InsufficientFundsException &e) {
        cout << "Error" << endl;
        cout << e.what() << endl;
    }
   
}