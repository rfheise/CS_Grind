#include <fstream>
#include <iostream>
#include <string>

using namespace std;


int main(void) {

    ifstream in = ifstream("./Romeo.txt");
    if (!in) {
        cout << "Bruh file be missin" << endl;
        return 1;
    }
    cout << "Give me a werd 😁" << endl;
    string search;
    cin >> search;
    string buff;
    int total = 0;
    int count = 0;
    cout << "Searching" << endl;
    while (in >> buff) {
        size_t index = buff.find(search);
        while(index != -1) {
            count++;
            buff = buff.substr(index + search.length());
            index = buff.find(search);
        }
        total++;
    }
    cout << "Total words searched " << total << endl;
    cout << "Word appeared " << count << " times in different words" << endl;
    in.close();
    
}