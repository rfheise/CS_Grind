#include <cstring>
#include <iostream>
#include "Strang.h"
using namespace std;
int main(void) {
    Strang x = Strang("f");
    x += x;
    cout << x << endl;
}
