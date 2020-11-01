#include <iostream>
#include <cstring>
#include "Strang.h"
#include <vector>


using std::cout;
using std::endl;
using std::vector;
using std::cin;

int main(void) {
    //call standard constructor
    Strang *epic = new Strang("char");
    //call copy constructor
    Strang *g = new Strang(*epic);
    cout << "Start 0" << endl;
    //call standard constructor
    //call overloaded move assignment operator
    //call Deconstructor
    *epic = "Bruh";
    cout << "End 0" << endl;
    cout << "Start 0" << endl;
    //call standard constructor
    //call overloaded move assignment operator
    //call Deconstructor
    *epic = Strang("bruh");
    cout << "End 0" << endl;
    cout << "Start 1" << endl;
    //call standard constructor
    //call overloaded copy assignment operator
    //call Deconstructor
    *epic = *g;
    cout << "End 1" << endl;
    cout << "Start 2" << endl;
    //standard constructor
    //overloaded Concatintation
    //no args constructor
    Strang y = "chuck berry " + *epic;
    cin >> y;
    cout << "End 2" << endl;
    cout << "Start" << endl;
    vector<Strang> x;
    x.push_back(Strang("bruh"));
    cout << "End" << endl;
    cout << y << endl;
    Strang xy = "no";
    delete epic;
    delete g;
}
