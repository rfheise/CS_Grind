#include "Hash.h"
#include <string>
#include <unordered_map>
#include <iostream>

using std::endl;
using std::cout;
using std::string;

int main(void) {
    // string s = "epic";
    // Hash<string> epicness = Hash<string>([] (string s) -> int{
    //     std::hash<string> h;
    //     return h(s);
    // });
    Hash<int> epicness = Hash<int>([](int i) -> int {
        return i;
    });
    int x = 1000000;
    for (int i = 0; i < x; i++) {
        epicness.add(i);
    }
    // cout << "not noice" << endl;
    for (int i = 0; i < x; i++) {
        epicness.check(i);
        // cout << "fin" << endl;
    }
    for (int i = 0,l = x/2; i < l; i++) {
        epicness.remove(i);
    }
    cout << "Done" << endl;

}
