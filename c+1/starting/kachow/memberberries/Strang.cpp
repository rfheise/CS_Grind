#include "Strang.h"
#include <cstring>
#include <iostream>

using namespace std;


Strang::Strang() {
    str = new char[1];
    str[0] = '\0';
}
Strang::Strang(Strang& source) {
    str = new char[strlen(source.str) + 1];
    strcpy(str,source.str);
}
Strang & Strang::operator=(Strang other) {
    std::swap(str,other.str);
    return *this;
}
Strang::Strang(Strang && source) {
    cout << "Move" << endl;
    delete[] str;
    str = source.str;
    source.str = nullptr;
}
Strang::Strang(const char *source) {
    str = new char[strlen(source)+1];
    strcpy(str,source);

}
Strang::~Strang() {
    cout << "Deconstuctor called for ";
    const char* temp;
    if (str == nullptr) {
        temp = "null";
    }
    else {
        temp = str;
    }
    cout << str << endl;
    delete[] str;
}
ostream & operator<<(ostream &os,const Strang &x) {
    os << x.str;
    return os;
}
Strang Strang::operator-() {
    Strang temp = Strang();
    char *buff = new char[strlen(str) + 1];
    for (int i = 0,len = strlen(str); i < len; i ++) {
        buff[i] = tolower(str[i]);
    }
    buff[strlen(str)] = '\0';
    delete[] temp.str;
    temp.str = buff;
    return temp;
}
bool Strang::operator==(Strang &other) {
    return strcmp(other.str,str) == 0;
}
bool Strang::operator!=(Strang &other) {
    return !(other == *this);
}
bool Strang::operator<(Strang &other) {
    return strcmp(str,other.str) < 0;
}
bool Strang::operator>(Strang &other) {
    return strcmp(str,other.str) > 0;
}
Strang Strang::operator+(Strang &other) {
    int lenone = strlen(str);
    int lentwo = strlen(other.str);
    Strang y = Strang();
    delete[] y.str;
    char *buff = new char[lenone+lentwo+1];
    for (int i = 0; i < lenone; i++){
        buff[i] = str[i];
    }
    for (int i = 0; i < lentwo; i++) {
        buff[i+lenone] = other.str[i];
    }
    y.str = buff;
    return y;
}
void Strang::operator+=(Strang& other){
    *this = (*this + other);
}
Strang Strang::operator*(int am) {
    Strang y = Strang();
    delete[] y.str;
    char * buff = new char[strlen(str) * am + 1];
    for (int i = 0; i < am; i++) {
        for (int j = 0,len = strlen(str); j < len; j++) {
            buff[j+i*len] = str[i];
        }
    }
    buff[strlen(str) * am] = '\0';
    y.str = buff;
    return y;

}
void Strang::operator*=(int am) {
    *this = (*this * am);
}
