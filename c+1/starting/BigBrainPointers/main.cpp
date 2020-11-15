#include <iostream>
#include <vector>

using std::vector;
using std::endl;
using std::cout;

int main(void) {
	vector<char *> b;
	for (int i = 0; i < 1000000; i++) {
		char *s = new char[2];
		s[0] = 'a' + i % 26;
		s[1] = '\0';
		b.push_back(s);
	}
	for (auto s : b) {
		cout << s << endl;
		delete[] s;
		
	}

}
