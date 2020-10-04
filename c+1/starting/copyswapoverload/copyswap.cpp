#include "fraction.h"
#include <iostream>

using std::cout;
using std::endl;


int main(void){

  Fraction x = Fraction(1,4);
  Fraction y;
  y = x;
  Fraction z = x+y;
  x += y;
  cout << "X:" << x.toDouble() << endl;
  cout << "Y:" << y.toDouble() << endl;
  cout << "Z num:" << z.getNum() <<  "Z den:" << z.getDen() << endl;
  cout << "Z:" << z.toDouble() << endl;

}
