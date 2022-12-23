/*
Name: Sahibpreet Singh
Student id: 165338211
email: sahibpreet-singh1@myseneca.ca
*/

/* Citation and Sources...
Final Project Milestone 4
Module: Menu
Filename: Menu.cpp
-----------------------------------------------------------
I have done all the coding by myself and used the code
provided in the starter files.
-----------------------------------------------------------*/
#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include "Vehicle.h"
namespace sdds {


	class Car :public Vehicle {

		bool carWash{ false };
	public:
		Car();
		Car(const char* plate, const char* model);
		Car(const Car&);
		Car& operator=(const Car&);
		std::ostream& writeType(std::ostream&)const;
		std::ostream& write(std::ostream&)const;
		std::istream& read(std::istream&);
		~Car();

	};

}
#endif