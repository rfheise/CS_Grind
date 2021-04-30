#include "ImageData.h"
#include <iostream>
#include <string>
using namespace std;

int main(void) {
    string filename;
    cout << "enter file name" << endl;
    cin >> filename;
    try {
        ImageData x(filename);
        x.decrypt();
    } catch (int a) {
        
    }
    
}