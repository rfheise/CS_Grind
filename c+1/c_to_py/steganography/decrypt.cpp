#include "ImageData.h"
#include <iostream>
#include <string>
using namespace std;

int main(void) {
    //using try catch to catch any errors I throw
    try {
        //gets filename to decrypt
        string filename;
        cout << "enter filename to decrypt" << endl;
        cin >> filename;
        //opens file and makes sure all is well
        ImageData x(filename);
        //asks if they want to output decrypted data to terminal
        //or if they want it in a file
        cout << "do you want to output decryption to a file" << endl;
        cout << "please enter yes or no" << endl;
        string yes;
        cin >> yes;
        //if they say yes prompt for filename and write
        //decrypted data to file
        if (yes == "yes") {
            cout << "please enter filename" << endl;
            cin >> filename;
            x.decrypt(filename);
        } else {
            //else just print out the data to terminal
            x.decrypt();
        }
    } catch (int a) {
        
    }
    
}