#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

int main(void) {

    ifstream in = ifstream("./Romeo.txt");
    ofstream out = ofstream("./copy.txt");
     if (!in || !out) {
        cerr << "bruh file not found" << endl;
        return 1;
    }
    size_t counter = 1;
    string buffer;
    while (getline(in, buffer)) {
        out << setw(10) << left << counter++ << buffer << endl;
    }
    in.close();
    out.close();


}