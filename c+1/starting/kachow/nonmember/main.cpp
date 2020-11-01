#include <cstring>
#include <iostream>
#include "Strang.h"
using namespace std;
int main(void) {
    Strang x = Strang("F");
    x *= 5;
    cout << (-x)<< endl;
}
