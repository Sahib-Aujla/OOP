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
#ifndef SDDS_PARKING_H
#define SDDS_PARKING_H
#include "Menu.h"
#include "Vehicle.h"

namespace sdds {
	const int MAX_PARK_SPOTS = 100;


	class Parking {
		char* parkFile{nullptr};
		int numSpots{};
		Vehicle* Vehicles[MAX_PARK_SPOTS]{nullptr};
		int parkedSpots{0};
		Menu mainMenu{ "Parking Menu, select an action:" };
		Menu vehicleMenu{ "Select type of the vehicle:",1 };
	
		bool loadFile();
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
		int emptySpot();
		void AssignCar();
		void AssignMotorCycle();
		int findingVehicleIndex();

		
	public:
		Parking(const char* file="\0", int noOfSpots = 0);
		~Parking();
		int run();
	};
	

}
#endif