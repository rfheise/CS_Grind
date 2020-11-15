#include "SimpleRick.h"
#include <iostream>
#include <string>
#include <memory>

using std::cout;
using std::endl;
using std::unique_ptr;
using std::shared_ptr;



void custom(char *arr) {
	delete[] arr;
}
int main(void) {

	// unique_ptr<char[]> c = unique_ptr<char[]>(new char[4]);
	//bad code just wanted to practice using a custom deleter function
	//never actually use a raw pointer and smart pointer
	char *x = new char[4];
	x[0] = 'x';
	x[1] = 'f';
	x[2] = '9';
	x[3] = '\0';
	shared_ptr<char> c = shared_ptr<char>(x, custom);

	cout << c << endl;

}
