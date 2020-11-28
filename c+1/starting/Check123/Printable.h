#ifndef _PRINTABLE_H_
#define _PRINTABLE_H_
#include <ostream>

using namespace std;

class Printable {
    friend ostream & operator<<(ostream &os, Printable &printer);
public:
    virtual ~Printable() = default;
    virtual string print() = 0;
};

#endif