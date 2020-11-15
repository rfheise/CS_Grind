#include "Nas.h"
#include <string.h>
#include <iostream>

using namespace std;

Nas::Nas()
	:Nas("Lil Nas X"){

}

Nas::Nas(const char *name){
	this -> name  = make_unique<char[]>(strlen(name) + 1);
	strcpy(this -> name.get(), name);
//	cout << "standard constructor called for "<<this -> name << endl;
}

Nas::~Nas() {
	//cout << "deconstructor called for " <<this->name << endl;
}
