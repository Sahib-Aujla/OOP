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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include<cstring>
#include "Parking.h"
#include "Motorcycle.h"
#include "Car.h"
#include "Menu.h"
#include "Utils.h"
using namespace std;

namespace sdds {


	Parking::Parking(const char* file, int noOfSpots) {

		if (file != nullptr && noOfSpots >= 10 && noOfSpots <= 100) {
			numSpots = noOfSpots;

			int len = strlen(file);
			parkFile = new char[len + 1];
			strcpy(parkFile, file);
			if (loadFile()) {
				mainMenu << "Park Vehicle" << "Return Vehicle" << "List Parked Vehicles" << "Find Vehicle" << "Close Parking (End of day)" << "Exit Program";
				vehicleMenu << "Car" << "Motorcycle" << "Cancel";

			}

		}
		else {
			cout << "Error in data file" << endl;
			parkFile = nullptr;
		}
	}

	bool Parking::loadFile() {
		bool isOk = false;


		if (!isEmpty()) {
			ifstream in;
			in.open(parkFile);
			parkedSpots = 0;
			if (in) {

				bool flag = true;
				while (in.good() && flag) {
					Vehicle* obj{ nullptr };

					char ch = 'V';
					in.get(ch);
					in.ignore();
					if (ch == 'M' || ch == 'C') {
						if (ch == 'M') {
							obj = new Motorcycle;

						}
						else {
							obj = new Car;
						}

						obj->setCsv(true);
						obj->read(in);
						if (!obj->isEmpty()) {
							int spot = 0;
							spot = obj->getParkingSpot();
							delete Vehicles[spot - 1];
							Vehicles[spot - 1] = nullptr;
							parkedSpots++;
							if (ch == 'M') {
								Vehicles[spot - 1] = new Motorcycle(obj->getLicensePlate(), obj->getMakeModel());
							}
							else {
								Vehicles[spot - 1] = new Car(obj->getLicensePlate(), obj->getMakeModel());
							}
							Vehicles[spot - 1]->setParkingSpot(spot);
							Vehicles[spot - 1]->setCsv(obj->isCsv());
							Vehicles[spot - 1]->setOption(obj->getOption());
							isOk = true;

						}
						delete obj;

					}
					if (in.eof() || parkedSpots > numSpots) {
						flag = false;
					}
					else if (in.fail()) {
						isOk = false;
						flag = false;
					}
				}

			}

			in.close();

		}

		return isOk;
	}
	bool Parking::isEmpty() {
		return parkFile == nullptr;
	}
	void Parking::status() {



		cout << "****** Valet Parking ******" << endl;
		cout << "*****  Available spots: ";
		cout.setf(ios::left);
		cout.width(4);
		cout << (numSpots - parkedSpots);
		cout.unsetf(ios::left);
		cout << " *****" << endl;

	}
	void Parking::parkVehicle() {

		if (parkedSpots >= numSpots) {
			cout << "Parking is full" << endl;
		}
		else {

			int selection = vehicleMenu.run();

			switch (selection)
			{
			case 1:

				AssignCar();
				break;
			case 2:

				AssignMotorCycle();

				break;
			case 3:
				cout << "Parking Cancelled" << endl;
			default:
				break;
			}

		}

	}
	void Parking::AssignMotorCycle() {
		int index = emptySpot();
		if (index != -1) {
			delete Vehicles[index];
			Vehicles[index] = nullptr;
			Vehicles[index] = new Motorcycle;
			Vehicles[index]->setCsv(false);
			Vehicles[index]->read(cin);
			Vehicles[index]->setParkingSpot(index + 1);
			parkedSpots++;
			cout << "\nParking Ticket" << endl;
			Vehicles[index]->write(cout);
			cout << endl;

		}

	}
	void Parking::AssignCar() {
		int index = emptySpot();
		if (index != -1) {
			delete Vehicles[index];
			Vehicles[index] = nullptr;
			Vehicles[index] = new Car;
			Vehicles[index]->setCsv(false);
			Vehicles[index]->read(cin);
			Vehicles[index]->setParkingSpot(index + 1);
			parkedSpots++;
			cout << "\nParking Ticket" << endl;
			Vehicles[index]->write(cout);
			cout << endl;
		}
	}

	int Parking::emptySpot() {
		int index = -1;
		bool flag = true;
		for (int i = 0; i < numSpots && flag; i++) {
			if (Vehicles[i] == nullptr) {
				index = i;
				flag = false;
			}
		}
		return index;
	}


	void  Parking::ReturnVehicle() {

		cout << "Return Vehicle" << endl;
		int index = findingVehicleIndex();

		if (index != -1) {
			cout << "\nReturning:" << endl;
			Vehicles[index]->setCsv(false);
			Vehicles[index]->write(cout);
			cout << endl;
			delete Vehicles[index];
			Vehicles[index] = nullptr;
			parkedSpots--;
		}


	}
	void  Parking::listVehicles() {

		cout << "*** List of parked vehicles ***" << endl;
		for (int i = 0; i < numSpots; i++) {
			if (Vehicles[i] != nullptr) {
				Vehicles[i]->setCsv(false);
				Vehicles[i]->write(cout);
				cout << "-------------------------------" << endl;

			}
		}
	}
	bool  Parking::closeParking() {

		cout << "This will Remove and tow all remaining vehicles from the parking!" << endl;
		cout << "Are you sure? (Y)es/(N)o: ";

		bool isOK = validChar();
		if (isOK) {
			cout << "Closing Parking" <<endl <<endl;
			for (int i = 0; i < numSpots; i++) {
				if (Vehicles[i] != nullptr) {
					cout << "Towing request" << endl;
					cout << "*********************" << endl;
					Vehicles[i]->setCsv(false);
					Vehicles[i]->write(cout);
if(i!=numSpots-1){					
cout << endl;}
					delete Vehicles[i];
					Vehicles[i] = nullptr;
				}
			}

		}
		return isOK;
	}
	int Parking::findingVehicleIndex() {
		bool flag = true;
		char temp[9]{};
		cout << "Enter Licence Plate Number: ";
		while (flag) {
			cin.getline(temp, 8, '\n');
			int len = strlen(temp);
			if (len == 0 || cin.fail()) {
				cout << "Invalid Licence Plate, try again: ";
			}
			else {
				flag = false;
			}
		}
		toUpperCase(temp);
		flag = true;
		int index = -1;
		for (int i = 0; i < numSpots && flag; i++) {
			if (Vehicles[i] != nullptr) {
				int res = strcmp(Vehicles[i]->getLicensePlate(), temp);
				if (res == 0) {
					flag = false;
					index = i;
				}

			}
		}
		if (index == -1) {
			cout << "\nLicense plate " << temp << " Not found" << endl << endl;
		}
		return index;
	}

	void Parking::findVehicle() {

		cout << "Vehicle Search" << endl;
		int index = findingVehicleIndex();

		if (index != -1) {
			cout << "\nVechicle found: " << endl;
			Vehicles[index]->setCsv(false);
			Vehicles[index]->write(cout);
			cout << endl;
		}

	}

	void Parking::SaveDataFile() {

		if (!isEmpty()) {
			ofstream os;

			os.open(parkFile);

			for (int i = 0; i < numSpots; i++) {
				if (Vehicles[i] != nullptr) {
					Vehicles[i]->setCsv(true);

					Vehicles[i]->write(os);
				}
			}
			os.close();
		}

	}
	Parking::~Parking() {

		SaveDataFile();
		for (int i = 0; i < numSpots; i++) {

			delete Vehicles[i];
			Vehicles[i] = nullptr;
		}
		delete[] parkFile;
	}
	bool Parking::exitParking() {
		cout << "This will terminate the program!" << endl;
		cout << "Are you sure? (Y)es/(N)o: ";

		bool isOK = validChar();
		if (isOK) {
			cout << "Exiting program!" << endl;
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
					cout << "Press <ENTER> to continue....";
					cin.get();
					cin.clear();
					

					break;
				case 2:
					ReturnVehicle();
					cout << "Press <ENTER> to continue....";
					cin.get();
					cin.clear();
					

					break;
				case 3:
					listVehicles();
					cout << "Press <ENTER> to continue....";
					cin.get();
					cin.clear();
					
					break;
				case 4:
					findVehicle();
					cout << "Press <ENTER> to continue....";
					cin.get();
					
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
