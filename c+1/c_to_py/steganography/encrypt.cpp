#include "ImageData.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(void) {
    //using a try catch just to catch any errors I throw
    try {
        //prompts user for bitmap filename
        string filename;
        cout << "enter bit map filename" << endl;
        cin >> filename;
        //makes sure file can open properly
        ImageData x(filename);
        //gets output file name
        cout << "enter name of out file" << endl;
        string outfile;
        cin >> outfile;
        //asks if they want to encrypt a file or text
        cout << "do you want to encrypt a file into the image" << endl;
        cout << "Please enter yes or no" << endl;
        string option;
        cin >> option;
        //if file encrypt using file method
        if (option == "yes") {
            //prompt for name of file to encrypt
            cout << "Please Enter Name of File to Encrypt" << endl;
            cin >> filename;
            ifstream f(filename, ios::binary);
            x.encrypt(f, outfile);
        } else {
            //gets text to encrypt
            cout << "Please Enter Text to Encrypt" << endl;
            string text;
            //clears cin buffer
            getline(cin,text);
            getline(cin,text);
            //encrypts text
            x.encrypt(text, outfile);
        }
        
    } catch (int a) {
        
    }
    
}