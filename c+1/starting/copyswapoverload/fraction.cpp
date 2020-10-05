#include "fraction.h"
#include <iostream>


using namespace std;


Fraction::Fraction(int num, int den)
:den(den),num(num)
{
  cout << "Standard Constructor Called" << endl;
}
void swap(Fraction &frac, Fraction &fractwo){
  swap(frac.num,fractwo.num);
  swap(frac.den,fractwo.den);
}

Fraction::~Fraction(){
  cout << "Deconstructor Called " << endl;
}
// without copy swap idiom
// Fraction & Fraction::operator=(Fraction & frac){
//   if(this == &frac){
//     return *this;
//   }
//   cout << "Copy Assignment operator called Without Copy Swap Idiom" << endl;
//   this -> den = frac.den;
//   this -> num = frac.num;
//   return *this;
// }

//r-value move assignment operator overload
//computationally expensive to make a copy
// Fraction & Fraction::operator=(Fraction && frac){
//     cout << "Swap called with Move Assignment operator" << endl;
//     swap(*this,frac);
//     return *this;
// }

//with copy swap idiom
//reuses copy constructors code at minimal computational cost
Fraction & Fraction::operator=(Fraction frac){
   cout << "Copy Assignment operator called With Copy Swap Idiom" << endl;
   // Fraction temp = frac;
  //don't check if they are equal since self assignment is rare and computationally expensive
  swap(*this,frac);
  return *this;
}
Fraction::Fraction(Fraction &source)
:Fraction(source.den,source.num){
  cout << "Copy Constructor called" << endl;
}
