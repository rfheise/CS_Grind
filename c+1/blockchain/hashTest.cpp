#include <iostream>
#include "sha256/sha256.h"
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

string to_binary(unsigned char* data, int size) {  
    char buff[size * 8];
    for (int i = 0; i < size; i++) {
        int start  = (1 << 7);
        for(int j = 7; j >= 0; j--) {
            buff[i*8 + (7 - j)] = ((data[i] & start) >> j) + '0';
            start >>= 1;
        }
    }
    return string(buff, size * 8);

}
string randString() {
    int size = rand() % 1000;
    char buffer[size];
    for(int i = 0; i < size; i++) {
        buffer[i] = rand() % 128;
    }
    return string(buffer, size);
}
int main(void) {
    srand(time(nullptr));
    rand();
    // unsigned int digest[8];
    unsigned char digest[256];
    digest[0] = 248;
    cout << to_binary(digest,1) << endl;
    do {
        sha256(randString(), (unsigned char *)digest);
    } while(digest[0] || digest[1] || (digest[2] & 248));
    cout << to_binary(digest, 32) << endl;
}