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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
#include "Parking.h"
#include "Menu.h"
#include "Utils.h"
using namespace std;

namespace sdds {

	Parking::Parking(const char* file) {
		 if(loadFile(file)) {
			 mainMenu << "Park Vehicle" << "Return Vehicle" << "List Parked Vehicles" << "Find Vehicle" << "Close Parking (End of day)" << "Exit Program";
			 vehicleMenu << "Car" << "Motorcycle" << "Cancel";
		}
		else {
			 cout << "Error in data file" << endl;
			parkFile = nullptr;
		}
	}

	bool Parking::loadFile(const char* file) {
		bool isOk = false;
		if (file!=nullptr && strlen(file) != 0) {
			parkFile = new char[strlen(file) + 1];
			strcpy(parkFile, file);
			cout << "---------------------------------" << endl;
			cout << "loading data from " << parkFile << endl;
			cout << "---------------------------------" << endl<<endl;
			isOk = true;
		}
		return isOk;
	}
	bool Parking::isEmpty() {
		return parkFile == nullptr;
	}
	void Parking::status() {

		cout << "****** Valet Parking ******" << endl;
	}
	void Parking::parkVehicle() {
		int selection=vehicleMenu.run();
		cout << "---------------------------------" << endl;
		switch (selection)
		{
		case 1:
			cout << "Parking Car" << endl;
			break;
		case 2:
			cout << "Parking Motorcycle" << endl;
			break;
		case 3:
			cout << "Cancelled parking" << endl;
		default:
			break;
		}
		cout << "---------------------------------" << endl<<endl;
	}
	
	void  Parking::ReturnVehicle() {
		cout << "---------------------------------"<<endl;
		cout << "Returning Vehicle" << endl;
		cout << "---------------------------------" << endl << endl;

	}
	void  Parking::listVehicles(){
		cout << "---------------------------------" << endl;
		cout << "Listing Parked Vehicles" << endl;
		cout << "---------------------------------" << endl << endl;
	}
	bool  Parking::closeParking(){
		
		cout << "This will close the parking; All the vehicles will be removed!" << endl;
		bool isOK= validChar();
		if (isOK) {
			cout << "Ending application!" << endl ;
		}
		return isOK;
	}

	void Parking::findVehicle() {
		cout << "---------------------------------" << endl;

		cout << "Finding a Vehicle" << endl;
		cout << "---------------------------------" << endl << endl;

	}

	void Parking:: SaveDataFile(){
		cout << "---------------------------------" << endl;
		cout << "Saving data into ParkingData.csv" << endl;
		cout << "---------------------------------" << endl ;
	}
	Parking::~Parking(){
		//SaveDataFile();
		delete[] parkFile;
	}
	bool Parking::exitParking() {
		cout << "This will terminate the application and save the data!" << endl;
		bool isOK = validChar();
		if (isOK) {
			cout << "Exiting application!" << endl;
			SaveDataFile();
		}
		return isOK;
	}

	int Parking::run() {
		bool done = false;
		int selection = 0;
		if (parkFile != nullptr) {
			while (!done) {
				status();
				selection = mainMenu.run();
				switch (selection)
				{
				case 1:
					parkVehicle();
					break;
				case 2:
					ReturnVehicle();
					break;
				case 3:
					listVehicles();
					break;
				case 4:
					findVehicle();
					break;
				case 5:
					done = closeParking();
					break;
				case 6:
					done = exitParking();
					break;
				default:
					break;
				}
			}
		}
		return selection;
	}
}