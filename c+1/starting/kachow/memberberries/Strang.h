#include <iostream>
using std::ostream;
class Strang {
    friend ostream & operator<<(ostream &os,const Strang& x);
    public:
        Strang();
        ~Strang();
        Strang(const char *source);
        Strang(Strang &source);
        Strang(Strang &&source);
        Strang & operator=(Strang other);
        Strang operator-();
        void operator*=(int am);
        Strang operator*(int am);
        void operator+=(Strang &other) ;
        Strang operator+(Strang &other);
        bool operator>(Strang &other) ;
        bool operator<(Strang &other);
        bool operator!=(Strang &other);
        bool operator==(Strang &other);

    private:
        char *str;
};
