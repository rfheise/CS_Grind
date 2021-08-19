#include <iostream>
#include <fstream>
#include <string>
#include "../transaction/User.h"
using namespace std;


int main(void) {
    //check to see if wallet already exists
    ifstream wallet(User::pubFile);
    //if it does ask user if they want to overwrite it
    if (wallet.good()) {
        cout << "It appears you already have an account fine sir" << endl;
        cout << "Would you like to overwrite it?" << endl;
        cout << "Y/n" << endl;
        string overwrite;
        cin >> overwrite;
        //if they don't want to overwrite it quit the program
        if (overwrite != "y" && overwrite != "Y") {
            cout << "Wise choice my friend" << endl;
            return 1;
        }
        //double check just to be sure
        cout << "Are you sure? You won't be able to recover" << endl;
        cout << "any of your precious flurbos every again 🥺" << endl;
        cout << "Y/n" << endl;
        cin >> overwrite;
        //if they don't want to overwrite it quit the program
        if (overwrite != "y" && overwrite != "Y") {
            cout << "Wise choice my friend" << endl;
            return 1;
        }
        cout << "Flushing your hopes & dreams 🚽" << endl;
    }
    cout << "Generating flurbo wallet now !!!" << endl;
    User *user = User::createUser();
    //if user not properly allocated 
    //throw an error
    if (!user) {
        cout << "An Error Occured" << endl;
        return 2;
    }
    delete user;
    cout << "Wallet Successfully Created" << endl;
    return 0;

}
