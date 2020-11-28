#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(void) {

    ifstream in = ifstream("./responses.txt");

    if (!in) {
        cerr << "bruh gimme some grades file be not real doo doo head" << endl;
        return 1;
    }

    string grades;
    in >> grades;

    int counter = 0;
    double sum = 0;
    while (!in.eof()) {
        string name, grade;
        in >> name >> grade;
        int score = 0;
        for (int i = 0; i < grade.length() || i < grades.length(); i++) {
            if (grade[i] == grades[i]) {
                score++;
            }
        }
        counter++;
        sum += score;
        cout << setw(15) << left << name  << score << endl;
    }
    cout << "Average was a " << sum/counter << endl;
    in.close();


}