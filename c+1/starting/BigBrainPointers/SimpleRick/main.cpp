#include "SimpleRick.h"
#include <iostream>
#include <string>

using namespace std;

int main(void) {

	SimpleRick<string> s = SimpleRick(new string("epic"));
	cout << s -> size() << endl;

}
