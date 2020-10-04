#include "fraction.h"
#include <iostream>

using std::cout;
using std::endl;
using std::swap;

void printer(const char * x){
  cout << x << endl;
}

Fraction::Fraction(int num, int den)
  :num(num), den(den){
    printer("Standard Constuctor Called");

}
Fraction::Fraction(){
  printer("Empty Constuctor called");
}

Fraction::Fraction(Fraction & source)
  :num(source.num),den(source.den){
    printer("Copy Constructor Called");
}

Fraction::Fraction(Fraction && source)
  :num(source.num),den(source.den){
    printer("Move Constructor Called");
}

Fraction & Fraction::operator=(Fraction &frac){
  printer("Copy Assignment Operator Called");
  //checks to see if self assignment
  if(&frac == this){
    //if so return reference to itself
    return *this;
  }
  this -> num = frac.num;
  this -> den = frac.den;
  return *this;

}
// Fraction & Fraction::operator+(Fraction &frac){
//   int den = this -> den * frac.den;
//   int num = this -> num * frac.den + frac.num * this -> den;
//   Fraction x = Fraction(num,den);
//   return x;
//
// }
Fraction Fraction::operator+(Fraction &frac){
  printer("Additon Operator Called");
  Fraction juice;
  juice.den = this -> den * frac.den;
  juice.num = this -> num * frac.den + frac.num * this -> den;
  cout << "Juice Num: " << juice.num;
  cout << " Juice Den: " << juice.den << endl;
  return juice;

}


Fraction::~Fraction(){
  printer("Destructor Called For Fraction");
}

Fraction & Fraction::operator=(Fraction &&frac){
    printer("Move Assignment Operator Called");
    if(&frac == this){
      //if so return reference to itself
      return *this;
    }
    this -> num = frac.num;
    this -> den = frac.den;
    return *this;

}
