#include "Printer.h"
#include <ostream>


std::ostream & operator<<(std::ostream &os, Printer &p) {
    return p.print(os);
}
