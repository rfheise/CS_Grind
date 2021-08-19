#ifndef __KEY__H
#define __KEY__H
#include <openssl/evp.h>
#include <fstream>
using namespace std;

class KeyGenException {

};

class Key {
private:
    //openssl key
    EVP_PKEY *key;
    //version of key that will get transmitted
    unsigned char* der;
    int derLen;
    //boolean that represents whether it is a private or public key
    bool isPrivateKey;
public:
    //flags for constructor
    const static constexpr int privateKey = 0x8;
    const static constexpr int publicKey = 0x1;
    const static constexpr int PEM = 0x02;
    const static constexpr int DER = 0x04;
    typedef struct KeyPair {
        Key *publicKey;
        Key *privateKey;
    } Keypair;
    //size in bits of rsa key
    const static constexpr int KEY_SIZE = 512;
    //creates a key from a der format given the following flags
    Key(unsigned char *der,int derLen, int flags);
    //creates a key from a file given the following flags
    Key(string filename, int flags);
    ~Key();
    //generates a key pair
    static KeyPair generateKeyPair(string publicFile, string privateFile);
};


#endif