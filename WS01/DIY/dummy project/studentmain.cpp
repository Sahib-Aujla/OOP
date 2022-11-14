#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "student.h"
using namespace std;
using namespace sdds;



int main() {

	Student st, st2; // in c style we write struct type
	st.set("John", 23); //don`t need to pass the reference of the odject
	//st.m_age = 20;  //for structure type we can directly change the data members
	st.display();
	st.clearmemory();

	st.set("jana", -1);
	st.display();
	st.clearmemory();

	st2.set(nullptr, 1);
	st2.display();
	st.clearmemory();
	//display(); //global; function;
	return 0;
}