#include "Blockchain.h"
#include <iostream>
using namespace std;


int main(void) {
    Blockchain chain{};
    chain.addBlock("noice");
    chain.addBlock("gordon ramsey");
    chain.addBlock("PC principal is trying to hunt down skank hunt");
    chain[0] -> setData("epic memer");
    cout << chain.isValid() << endl;
    chain.mineChain();
    cout << chain.isValid() << endl;
}
