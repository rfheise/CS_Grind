
#include <iostream>
#include <string>

using namespace std;

typedef struct{
  int value;
}
hi;
int main(void){
  cout << "Comparing as C Strings" << endl;
  char s1[7];
  char s2[7];
  const char *x = "string";
  for(int i =0 ; i < 7; i ++){
    s1[i] = x[i];
    s2[i] = x[i];
    // cout << x[i] << endl;
  }
  cout << "address: " << static_cast<const void*>(s1) << endl;
  cout << "address: " <<static_cast<const void*>(s2) << endl;
  cout << "value: " << s1 << endl;
  cout << "value: " << s2 << endl;
  cout << "Comparing Addresses: "<<(static_cast<const void*>(s1) == static_cast<const void*>(s2)? "true":"false") << endl;
  cout << "Comparing Values: "<<((s1 == s2)? "true":"false") << endl << endl;
  cout << "Comparing as C++ Strings" << endl;


  string *s3 = new string("string");
  // string s5("string");
  string *s4;
  string s6("string");
  s4 = &s6;
  // s3 = &s5;
  cout << "test" << endl;

  cout << "address: " << s3 << endl;
  cout << "address: " << s4 << endl;
  cout << "value: " << *s3 << endl;
  cout << "value: " << *s4 << endl;
  cout << "Comparing Addresses: "<<(s3 == s4? "true":"false") << endl;
  cout << "Comparing Values: "<<((*s3 == *s4)? "true":"false") << endl << endl;

}
