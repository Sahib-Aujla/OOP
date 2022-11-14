#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include "Student.h"
using namespace std;

void display() {

	cout << "Global function" << endl;
}


namespace sdds {

	/*void Student::display2() const {

		cout << "Student age: " << m_age << endl;
	}*/

	void student::display() const { //member function accessing from outside of the struct
		::display();
		if (!isempty()) {
			cout << "student name: " << m_name << endl;
			//cout << m_age << endl;
			display2();
		}
		else
			cout << "invalid values" << endl;
	}

	void Student::set(const char* nam, int ag) {

		if (!nam || nam[0] == '\0' || strlen(nam) == 0 || ag < 1) { //lazy evaluation
		//if (nam==nullptr || nam[0]=='\0'|| ag < 1) {
			setEmpty();
		}

		else {

			int len = strlen(nam);
			m_name = new char(len + 1);
			strcpy(m_name, nam);
			m_age = ag;
		}


	}
	void Student::setEmpty() {

		m_name = nullptr; //important that you assign default value as nullptr if you check set validation as null first
		m_age = 0;

	}

	bool Student::isEmpty() const {

		bool empty = false;
		if (m_name == nullptr || m_age < 1)
			empty = true;

		return empty;

		//return m_name == nullptr || m_name[0]=='\0'|| m_age < 1;
	}


	void Student::clearmemory() {

		cout << "Clearing Memory" << endl;
		delete[] m_name;
		//m_name = nullptr;

	}
}