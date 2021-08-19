#ifndef __USER__H
#define __USER__H
#include <fstream>
#include "Key.h"
using namespace std;
class User {
private:
    //public and private keys
    Key *pubKey;
    Key *privKey;
public:
    //default public and private key files
    const static constexpr char * pubFile = "flurbo-public.pem";
    const static constexpr char * privFile = "flurbo-private.pem";
    //loads in public and private keys from file
    User();
    //takes in private and public Key pointers to create user
    User(Key *pubKey, Key *privKey);
    //static method for generating a user
    //returns an allocated user object
    static User *createUser();
    ~User();
};

#endif