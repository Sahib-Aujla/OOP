/*
Name: Sahibpreet Singh
Student id: 165338211
email: sahibpreet-singh1@myseneca.ca
*/

/* Citation and Sources...
Final Project Milestone 2
Module: Menu
Filename: Menu.cpp
-----------------------------------------------------------
I have done all the coding by myself and used the code
provided in the starter files.
-----------------------------------------------------------*/
#ifndef SDDS_PARKING_H
#define SDDS_PARKING_H
#include "Menu.h"

namespace sdds {
	class Parking {
		char* parkFile;
		Menu mainMenu{ "Parking Menu, select an action:" };
		Menu vehicleMenu{ "Select type of the vehicle:",1 };
	
		bool loadFile(const char*);
		bool isEmpty();

		Parking(const Parking&) = delete;
		Parking& operator=(Parking&) = delete;
		void status();
		void parkVehicle();
		void ReturnVehicle();
		void listVehicles();
		bool closeParking();
		bool exitParking();
		void findVehicle();
		void SaveDataFile();
		
		
	public:
		Parking(const char*);
		~Parking();
		int run();
	};
	

}
#endif