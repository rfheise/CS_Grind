#include "Key.h"
#include <openssl/evp.h>
#include <openssl/rsa.h>
#include <openssl/bio.h>
#include <openssl/pem.h>
#include <stdio.h>
#include "User.h"
#include <iostream>
#include <openssl/buffer.h>
using namespace std;

//creates a key from a der format given the following flags
Key::Key(unsigned char *derCpyCpy,int derLen, int flags) {
    //copy der 
    unsigned char *der = new unsigned char[derLen];
    unsigned char *derCpy = new unsigned char[derLen];
    for (int i = 0; i < derLen; i++) {
        der[i] = derCpyCpy[i];
        //have to copy because when creating key
        //the function frees the passed in der
        //want to preserver der in parent functions
        derCpy[i] = derCpyCpy[i];
    }
    //check to make sure der format passed in
    if (!(flags & Key::DER)) {
        throw KeyGenException();
    }
    EVP_PKEY *pkey;
    //convert key from der format
    //see delete comment below
    unsigned char *buffer = derCpy;
    if (flags & Key::privateKey) {
        pkey = d2i_PrivateKey(EVP_PKEY_RSA, NULL, (const unsigned char**)(&derCpy), derLen);
    } else {
        pkey = d2i_PublicKey(EVP_PKEY_RSA, NULL, (const unsigned char**)(&derCpy), derLen);
    }
    //for some reason d2i replaces pointer in derCpy but doesn't 
    //free the memory
    //this is to correct that
    delete [] buffer;
    //if pkey not allocated throw exception
    if (pkey == NULL) {
        throw KeyGenException();
    }
    //set fields of instance
    this ->der = der;
    this -> derLen = derLen;
    this -> isPrivateKey = flags & Key::privateKey;
    this -> key = pkey;
}
//creates a key from a file given the following flags
Key::Key(string filename, int flags) {
    //open file
    FILE *file = fopen(filename.c_str(), "r");
    //make sure file exists
    if (!file) {
        throw KeyGenException();
    }
    //read in key from file
    if (flags & Key::privateKey) {
        key = PEM_read_PrivateKey(file, NULL, NULL, NULL);
    } else {
        key = PEM_read_PUBKEY(file, NULL, NULL, NULL);
    }
    //close key
    fclose(file);
    //make sure key read properly
    if (!key) {
        throw KeyGenException();
    }
    if (flags & Key::privateKey) {
        derLen = i2d_PrivateKey(key, &der);
    } else {
        derLen = i2d_PublicKey(key, &der);
    }
    isPrivateKey = flags & Key::privateKey;
    
}

//generates a key pair
Key::KeyPair Key::generateKeyPair(string publicFile, string privateFile) {
    EVP_PKEY *pkey = nullptr;
    //sets up context for key
    EVP_PKEY_CTX *ctx = EVP_PKEY_CTX_new_id(EVP_PKEY_RSA,NULL);
    if (!ctx) {
        throw KeyGenException();
    }
    if (EVP_PKEY_keygen_init(ctx) <= 0) {
        throw KeyGenException();
    }
    if (EVP_PKEY_CTX_set_rsa_keygen_bits(ctx, 512) <= 0) {
        throw KeyGenException();
    }
    //generates key pair
    if (EVP_PKEY_keygen(ctx, &pkey) <= 0) {
        throw KeyGenException();
    }
    //open public and private files
    FILE *pubfile = fopen(publicFile.c_str(), "w");
    //if files do not exist throw an error
    if (!pubfile) {
        //free key
        EVP_PKEY_free(pkey);
        EVP_PKEY_CTX_free(ctx);
        throw KeyGenException();
    }
    FILE *privfile = fopen(privateFile.c_str(), "w");
    if (!privfile) {
        //free key
        EVP_PKEY_CTX_free(ctx);
        fclose(pubfile);
        EVP_PKEY_free(pkey);
        throw KeyGenException();
    }
    //writes keys to file in pem format
    int out = PEM_write_PUBKEY(pubfile, pkey);
    int in = PEM_write_PrivateKey(privfile,pkey, NULL,
                            NULL, 0, NULL, NULL);
    
    //free keys
    fclose(pubfile);
    fclose(privfile);
    //gets derformat of private and public keys
    unsigned char *derPriv = 0;
    unsigned char *derPub = 0;
    int derLenPriv = i2d_PrivateKey(pkey, &derPriv);
    int derLenPub = i2d_PublicKey(pkey, &derPub);
    //final error checker
    //make sure none of these values equals 0 or is less than 0
    if ((out | derLenPriv | in | derLenPub) <= 0 ) {
        throw KeyGenException();
    }
    //creates and returns key pair object
    //creates with der because copying EVP_PKEY is a nightmare
    Key *privateKey = new Key(derPriv, derLenPriv, Key::privateKey | Key::DER);
    Key *publicKey =  new Key(derPub, derLenPub, Key::publicKey | Key::DER);
    //frees public key and key context
    EVP_PKEY_free(pkey);
    EVP_PKEY_CTX_free(ctx);
    OPENSSL_free(derPub);
    OPENSSL_free(derPriv);
    KeyPair keys;
    keys.privateKey = privateKey;
    keys.publicKey = publicKey;
    return keys;
}

Key::~Key() {
    delete [] der;
    EVP_PKEY_free(key);
}