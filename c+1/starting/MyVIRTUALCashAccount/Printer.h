#ifndef _PRINTER_H_
#define _PRINTER_H_
#include <ostream>

class Printer {
    friend std::ostream & operator<<(std::ostream &os, Printer &p);
public:
    virtual std::ostream & print(std::ostream &os) = 0;
    virtual ~Printer() = default;
};

#endif
