#include <cstring>
#include <iostream>
#include "Strang.h"
using namespace std;

int main(void) {
    Strang x = Strang("F");
    Strang y = x ++;
    cout << x<< endl;

}
