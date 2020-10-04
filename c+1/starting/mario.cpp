#include <iostream>

using std::cout;
using std::endl;
using std::cin;


void recursive_mario(int x);
int get_integer(const char *welcome);
int main(void){
  int x = get_integer("Give Me an Integer: ");
  recursive_mario(x);
  return 0;
}

int get_integer(const char *welcome){
  cout << welcome;
  int l;
  cin >> l;
  cout << endl;
  return l;
}

void recursive_mario(int x){
  if(x == 0){
    return;
  }
  recursive_mario(x-1);
  for(int i = 0; i < x; i++){
    cout << "#";
  }
  cout << endl;
}
