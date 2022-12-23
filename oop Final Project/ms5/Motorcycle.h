/*
Name: Sahibpreet Singh
Student id: 165338211
email: sahibpreet-singh1@myseneca.ca
*/

/* Citation and Sources...
Final Project Milestone 5
Module: Menu
Filename: Menu.cpp
-----------------------------------------------------------
I have done all the coding by myself and used the code
provided in the starter files.
-----------------------------------------------------------*/
#ifndef SDDS_MOTORCYCLE_H
#define SDDS_MOTORCYCLE_H
#include "Vehicle.h"

namespace sdds {
	class Motorcycle :public Vehicle {
		bool sideCar{ false };
	public:
		Motorcycle();
		Motorcycle(const char* plate, const char* model);
		Motorcycle(const Motorcycle&);
		virtual Motorcycle& operator=(const Motorcycle&);
		
		 void setOption(bool isCar);
		 bool getOption()const;
		~Motorcycle();

		 std::ostream& writeType(std::ostream&)const;
	     std::ostream& write(std::ostream&)const;
		 std::istream& read(std::istream&);
	};
}


#endif	
