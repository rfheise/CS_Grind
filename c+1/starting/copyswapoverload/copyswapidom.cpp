#include "fraction.h"
#include <iostream>

using namespace std;

int main(void){
  //standard constructor
  Fraction x = Fraction(1,2);
  //copy constructor calls standard constructor
  //copy constructor finishes executing
  Fraction y = x;
  //standard constructor executed
  Fraction z = Fraction(1,4);
  //copy constructor Calls standard constructor
  //copy constructor finishes
  //swaps copy with current
  //deconstructs the copy
  y = z;
  //standard constructor called
  // move assigment operator called
  //don't need move constructor? because it is already being passed in by value
  //I would have thought that it would have called the standard constructor and then the copy constructor I wonder why it didn't
  z = Fraction(1,2);
  //all deconstructors called
}
