#include "ImageData.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(void) {
    string filename;
    cout << "enter file name" << endl;
    cin >> filename;
    try {
        ImageData x(filename);
        ifstream file("beemovie.txt");
        x.encrypt(file);
    } catch (int a) {
        
    }
    
}