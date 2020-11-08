#include <iostream>
#include "Account.h"
#include "SavingsAccount.h"
#include "Checking.h"
#include "Trust.h"

using namespace std;


int main(void) {
    Trust *me = new Trust(1000, .5, "bruh");
    *me += 5;
    me -> deposit(5000);
    cout << (*me) << endl;
    delete me;
}
