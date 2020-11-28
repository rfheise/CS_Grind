#include "Printable.h"
#include <iostream>

ostream & operator<<(ostream & os, Printable &printer) {
    cout << printer.print();
    return os;
}
