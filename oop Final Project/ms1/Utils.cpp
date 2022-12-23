/*
Name: Sahibpreet Singh
Student id: 165338211
email: sahibpreet-singh1@myseneca.ca
*/

/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.cpp
-----------------------------------------------------------
I have done all the coding by myself and used the code
provided in the starter files.
-----------------------------------------------------------*/
/***********************************************************************
// Utils Module
// File  utils.cpp
// Version 0.0
// Date
// Author
// Description
// Estra Classes and functions needed in the project
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "Utils.h"

using namespace std;

namespace sdds {
	int validInt() {
		int selection, flag = 0;
		while (flag == 0) {

			cin >> selection;
			if (cin.fail()) {
				cout << "Invalid Integer, try again: ";
				cin.clear();
				cin.ignore(1000, '\n');

			}
			else {
				flag = 1;
			}
		}
		return selection;
	}
			

}