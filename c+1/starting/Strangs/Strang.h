#include <iostream>

class Strang {
    friend std::ostream & operator<<(std::ostream &os, const Strang& x);
    friend std::istream & operator>>(std::istream &is, Strang & x);
    friend Strang operator+(const Strang& one, const Strang& two);
    public:
        Strang();
        Strang(const char *strange);
        ~Strang();
        Strang(Strang &source);
        Strang(Strang &&source);
        //with copy swap idiom
        // Strang & operator=(Strang source);
        Strang & operator=(Strang &other);
        Strang & operator=(Strang &&other);
        char * getStrang() const;

    private:
        char * str;
};
