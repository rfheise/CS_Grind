#include "sha256/sha256.h"
#include "Block.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main(void) {
    srand(time(nullptr));
    rand();
    BYTE arr[32] = {0};
    Block block(arr, "PC princible prevents micro-aggressions");
    block.mine();
    cout << block << endl;
}