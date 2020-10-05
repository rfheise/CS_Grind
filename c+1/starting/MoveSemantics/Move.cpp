#include <iostream>
#include "Move.h"
#include <string>

using namespace std;


Move::Move(string s){
  cout << "Standard Constructor Called" << endl;
  str = new string(s);
}

Move::Move(Move && source){
  cout << "Move Constructor Called" << endl;
  str = source.str;
  source.str = nullptr;
}

Move::Move(Move & source){
  //deep copy
  cout << "Copy Constructor Called" << endl;
  str = new string(*(source.str));
}

Move::~Move(){
  cout << "Destructor Called" << endl;
  delete str;
}
