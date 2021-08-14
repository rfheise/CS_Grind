#ifndef __BLOCK__H
#define __BLOCK__H
#include <string>
using namespace std;
// enum class BYTE : unsigned char;
typedef unsigned char BYTE; 
class Block {

private:
    //boolean to determine if mined
    bool mined;
    //size of nonce array
    int nonceSize;
    //nonce value used to create a valid hash
    BYTE *nonce;
    //prev hash value must be of size 32
    BYTE *prevHash;
    //data stored in chain
    string data;
    //generates a random nonce
    void generateNonce();
    //max nonce size
    static constexpr int maxNonceSize = 500;
public:
    //hash size
    static constexpr int hashSize = 32;
    //determines if the block is valid
    bool isValid() const;
    //returns hash value
    BYTE * getHash(BYTE *arr) const;
    //returns string of hash in binary
    string binaryHash() const;
    //updates prev hash value
    void setPrevHash(const BYTE *arr);
    //creates a block
    Block(BYTE *prevHash, string data);
    //"mines block" makes it's hash valid
    void mine();
    //returns copy of data
    string getData();
    //determines if a hash is valid
    static bool isValid(const BYTE *hash);
    //block destructor
    ~Block();
    //updates data
    void setData(string data);
    //returns hexadecimal representation of hash
    string hexHash() const;
    friend ostream& operator<<(ostream &os, const Block &block);    
};
ostream& operator<<(ostream &os, const Block &block); 
#endif