#include<iostream>
#include "Strang.h"
#include <cstring>

using std::cout;
using std::endl;
using std::cin;
using std::strlen;

Strang::Strang()
    :str(new char[1]){
        cout << "Standard non argument Constructor called" << endl;
        str[0] = '\0';
}

Strang::Strang(const char *strange) {
    //room for null character
    str = new char[strlen(strange) + 1];
    strcpy(str,strange);
    cout << "Standard Constructor called" << endl;
}

Strang::~Strang(){
    cout << "Deconstructor Called" << endl;
    delete[] str;
}
char * Strang::getStrang() const {
    return str;
}
//with copy swap idiom
// Strang & Strang::operator=(Strang source){
//     cout << "Overloaded assignment operator called with copy swap idiom" << endl;
//     std::swap(str,source.str);
//     return *this;
// }

//without copy swap idiom
Strang & Strang::operator=(Strang &other) {
    cout << "Overloaded assignment operator called" << endl;
    if (this == &other) {
        return  *this;
    }
    char * temp = new char[strlen(other.str) + 1];
    temp[strlen(other.str)] = '\0';
    strcpy(temp,other.str);
    delete[] this -> str;
    this -> str = temp;
    return *this;
}
Strang & Strang::operator=(Strang && other) {
    cout << "overloaded move assignemnt operator called" << endl;
    this -> str = other.str;
    other.str = nullptr;
    return *this;
}
Strang::Strang(Strang &source) {
    cout << "Copy Constructor Called" << endl;
    int length = strlen(source.str);
    str = new char[length + 1];
    for (int i = 0; i < length; i++) {
        str[i] = source.str[i];
    }
    str[length] = '\0';
}
std::istream & operator>>(std::istream &is, Strang & x) {
    char *buff = new char[1000];
    is >> buff;
    delete[] x.str;
    x.str = buff;
    return is;
}
std::ostream & operator<<(std::ostream &os, const Strang& x) {
    os << x.getStrang();
    return os;
}
Strang operator+(const Strang& one, const Strang& two) {
    cout << "Overloaded Global Concatintation function called" << endl;
    Strang x = Strang();
    delete[] x.str;
    char *buff = new char[strlen(one.str)+strlen(two.str)+1];
    int lenone = strlen(one.str);
    for (int i = 0; i < lenone; i++) {
        buff[i] = one.str[i];
    }
    for (int i = 0,len = strlen(two.str); i < len; i++) {
        buff[lenone + i] = two.str[i];
    }
    buff[lenone+strlen(two.str)] = '\0';
    x.str = buff;
    return x;
}
Strang::Strang(Strang &&source) {
    cout << "Move Constructor Called" << endl;
    str = source.str;
    source.str = nullptr;
}
