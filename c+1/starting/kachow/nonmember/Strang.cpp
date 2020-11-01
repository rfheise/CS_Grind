#include <iostream>
#include <cstring>
#include "Strang.h"


Strang::~Strang() {
    delete[] str;
}
Strang::Strang()
    :str(nullptr){

}
Strang::Strang(const Strang &x) {
    str = new char[strlen(x.str) +1];
    strcpy(str,x.str);
}
Strang::Strang(const char*x) {
    str = new char[strlen(x) + 1];
    strcpy(str,x);
}
Strang& Strang::operator=(Strang other) {
    swap(str,other.str);
    return *this;
}
bool operator==(const Strang &first,const Strang &second) {
    return strcmp(first.str,second.str) == 0;
}
bool operator!=(const Strang &first,const Strang &second) {
    return !(first == second);
}
bool operator<(const Strang &first,const Strang &second) {
    return strcmp(first.str,second.str) < 0;
}
bool operator>(const Strang &first,const Strang &second) {
    return strcmp(first.str,second.str) > 0;
}
Strang operator+(const Strang &first,const Strang &second) {
    int one = strlen(first.str);
    int two = strlen(second.str);
    char *x = new char[one+two+1];
    strcpy(x,first.str);
    strcat(x,second.str);
    Strang y = Strang();
    y.str = x;
    return y;
}
Strang& operator+=(Strang &first,const Strang &second) {
    first = first + second;
    return first;
}
Strang operator*(const Strang &first,const int x) {
    char * temp = new char[strlen(first.str)*x+1];
    temp[0] = '\0';
    for(int i = 0; i < x; i++) {
        strcat(temp,first.str);
    }
    Strang y = Strang();
    y.str = temp;
    return y;

}
Strang& operator*=(Strang &first,const int x) {
    first = first * x;
    return first;
}
Strang& Strang::operator++() {
    *this *= 2;
    return *this;
}
Strang Strang::operator++(int) {
    Strang temp = *this;
    *this *= 2;
    return *this;
}
ostream& operator<<(ostream &os,const Strang &x) {
    os << x.str;
    return os;
}
