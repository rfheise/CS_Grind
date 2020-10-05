#include "Move.h"
#include <iostream>
#include <vector>

using namespace std;


int main(void){
  //call standard constructor
  Move x = Move("string");
  //call copy constructor
  Move y = x;
  vector<Move> z;

  //call standard constructor

  //call move constructor
  //destruct og
  //computationally efficient as it doesn't have to re allocate memory
  z.push_back(Move("string"));


}
