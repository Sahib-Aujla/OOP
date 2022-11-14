/*
Name: Sahibpreet Singh
Student id: 165338211
email: sahibpreet-singh1
date of submission: 30/09/2022
*/
#include <iostream>
#include "Utils.h"
#include "NameTag.h"

using namespace std;

namespace sdds {
	void NameTag::set(const char * name) {
		strcpy(nametag, name);
	}
	int NameTag::countTheLongest() {
		int len = strlen(this->nametag);
		return len;
	}
	void NameTag::printName(int len) {
		int i = 0;
		for (i = 0; i < len+4; i++) {
			cout << "*";
		}
		cout << endl;
		cout << "* ";
		cout.width(len);
		cout.setf(ios::left);
		cout << this->nametag;
		cout.width(0);
		cout.unsetf(ios::left);
		cout << " *"<<endl;
		for (i = 0; i < len + 4; i++) {
			cout << "*";
		}
		cout << endl;
	}
}
