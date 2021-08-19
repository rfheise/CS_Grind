#include "User.h"
#include "Key.h"

//loads in public and private keys from file
User::User() {
    pubKey = new Key(User::pubFile, Key::PEM | Key::publicKey);
    privKey = new Key(User::privFile, Key::PEM | Key::privateKey);
}
User::User(Key *pubKey, Key *privKey) {
    this -> pubKey = pubKey;
    this -> privKey = privKey;
}
//static method for generating a user
User *User::createUser() {
    Key::Keypair keys = Key::generateKeyPair(User::pubFile, User::privFile);
    return new User(keys.publicKey, keys.privateKey);
}
User::~User() {
    delete pubKey;
    delete privKey;
}
