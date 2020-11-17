#include <unordered_set>

using std::unordered_set;


int main(void) {

    unordered_set<int> epicness = unordered_set<int>();

    for (int i = 0; i < 1000000; i++) {
        epicness.insert(i);
    }
    for (int i = 0; i < 1000000; i++) {
        epicness.find(i);
    }
    for (int i = 0; i < 1000000; i++) {
        epicness.erase(i);
    }

}
