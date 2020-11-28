#include "Account.h"
#include "IllegalBalanceException.h"

Account::Account(const double balance, const char *name)
    :name(name), balance(balance) {
        if (balance < 0) {
            throw IllegalBalanceException();
        }
}