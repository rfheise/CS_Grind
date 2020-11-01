#include <iostream>
using namespace std;

class Strang {
    friend bool operator==(const Strang &first,const Strang &second);
    friend bool operator!=(const Strang &first,const Strang &second);
    friend bool operator<(const Strang &first,const Strang &second);
    friend bool operator>(const Strang &first,const Strang &second);
    friend Strang operator+(const Strang &first,const Strang &second);
    friend Strang& operator+=(Strang &first,const Strang &second);
    friend Strang operator*(const Strang &first,const int x);
    friend Strang& operator*=(Strang &first, const int x);
    friend ostream& operator<<(ostream &os,const Strang &x);


public:
    Strang& operator=(Strang other);
    Strang();
    Strang(const Strang &x);
    Strang(const char *x);
    ~Strang();
    Strang& operator++();
    Strang operator++(int);
private:
    char * str;

};
