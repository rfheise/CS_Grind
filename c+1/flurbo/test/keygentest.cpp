#include "../transaction/Key.h"
#include <string>
#include <iostream>
using namespace std;

int main(void) {
    try {
        Key::KeyPair keys = Key::generateKeyPair("public.pem","private.pem");
        delete keys.privateKey;
        delete keys.publicKey;
    } catch(KeyGenException e) {
        cout << "An Error Has Occurred !" << endl;
    }
}