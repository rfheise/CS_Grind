#include "Nas.h"
#include <iostream>
#include <memory>
#include <vector>
#include <math.h>
using namespace std;

unique_ptr<vector<shared_ptr<Nas>>> make();
void fill(vector<shared_ptr<Nas>> &vec, int am) {
	int len = 0;
	for (int i = 0; i < am; i++) {
		//not efficent way to do this but just to show poc
		
		unique_ptr<char[]> c = make_unique<char[]>(2);
		c[0] = 'a' + i % 26;
		c[1] = '\0';
		shared_ptr<Nas> obj = shared_ptr<Nas>(new Nas(c.get()));
		vec.push_back(obj);
	
	}
}

void display(vector<shared_ptr<Nas>> &vec) {
	
	for(auto v : vec) {
		cout << v -> getName() << endl;
	
	}

}

int main(void) {
	unique_ptr<vector<shared_ptr<Nas>>> vec;
	vec = make();
	cout << "Bruh gimme da goods" << endl;
	int num = 1000000;
	//cin >> num;
	fill(*vec, num);
	display(*vec);

	//cout << (vec -> at(vec -> size() - 1)) -> getName() << endl;
}


unique_ptr<vector<shared_ptr<Nas>>> make() {
	
	return make_unique<vector<shared_ptr<Nas>>>();

}


