#include <iostream>
using std::ostream;
class Strang {
    friend ostream & operator<<(ostream &os,const Strang& x);
    friend int main(void);
    public:
        Strang();
        ~Strang();
        Strang(const char *source);
        Strang(Strang &source);
        Strang(Strang &&source);
        Strang & operator=(Strang other);
        Strang operator-();
        Strang & operator*=(int am);
        Strang operator*(int am);
        Strang& operator+=(const Strang &other);
        Strang operator++(int);
        Strang& operator++();
        Strang operator+(const Strang &other);
        bool operator>(Strang &other) ;
        bool operator<(Strang &other);
        bool operator!=(Strang &other);
        bool operator==(Strang &other);

    private:
        char *str;
};
