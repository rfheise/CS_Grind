#include <iostream>
#include "Account.h"
#include "SavingsAccount.h"
#include "Checking.h"
#include "Trust.h"

using namespace std;


int main(void) {
    Account *me = new Checking(1000);
    for (int i = 0; i < 4; i ++){
        me -> deposit(1);
        me -> withdraw(1);
    }
    cout << (*me) << endl;
    delete me;
}
