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
    for (int i = 0; i < 1000000; i++) {
        epicness.add(i);
    }
    // for (int i = 0; i < 1000000; i++) {
    //     epicness.check(i);
    // }
    // for (int i = 0; i < 1000000; i++) {
    //     epicness.remove(i);
    // }
    cout << "Done" << endl;

}
