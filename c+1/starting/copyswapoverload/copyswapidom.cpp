#include "fraction.h"
#include <iostream>
#include <vector>

using namespace std;

int main(void){
  //standard constructor
  Fraction x = Fraction(1,2);
  //copy constructor calls standard constructor
  //copy constructor finishes executing
  Fraction y = x;
  //standard constructor executed
  cout << "Start 1" << endl;
  Fraction z = Fraction(1,4);
  cout << "Done 1" << endl;

  //copy constructor Calls standard constructor
  //copy constructor finishes
  //swaps copy with current
  //deconstructs the copy
  cout << "Start 2" << endl;
  y = z;
  cout << "Done 2" << endl;

  //standard constructor called
  // move assigment operator called
  //don't need move constructor? because it is already being passed in by value
  //I would have thought that it would have called the standard constructor and then the copy constructor I wonder why it didn't
  cout << "Start 3" << endl;
  z = Fraction(1,2);
  cout << "Done 3" << endl;
  cout << "Start 4" << endl;
  vector<Fraction> v = vector<Fraction>();
  v.push_back(z);
  cout << "Done 4" << endl;
  //all deconstructors called
}
