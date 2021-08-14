#include "Blockchain.h"
#include <iostream>
using namespace std;


int main(void) {
    Blockchain chain{};
    cout << "Blockchain created go ahead and add some blocks" << endl;
    cout << "enter done stop adding and do block chain analysis" << endl;
    string data;
    while(true) {
        cout << "Enter string here: ";
        cin >> data;
        if (data != "done") {
            chain.addBlock(data);
        } else {
            cout << endl;
            break;
        }
    }
    cout << chain << endl;
}
