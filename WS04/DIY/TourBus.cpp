/*
Name: Sahibpreet Singh
Student id: 165338211
email: sahibpreet-singh1@myseneca.ca
Date of completion: 07 octtober 2022
*/

#include <iostream>
#include "TourBus.h"

using namespace std;

namespace sdds {
	TourBus::TourBus() {
		tourTick = nullptr;
		reset();
	}
	void TourBus::set() {
		if (validTour()) {
			tourTick = new TourTicket[totalPassengers];
		}
		else {
			reset();
		}
	}
	TourBus::TourBus(int pass) {
		totalPassengers = pass;
		if (validTour()) {
			set();
		}
		else {
			reset();
		}
	}

	bool TourBus::validTour() const {
		bool isOk = false;
		if (totalPassengers == 4 || totalPassengers == 16 || totalPassengers == 22) {
			isOk= true;
		}
		return isOk;
	}
	void TourBus::startTheTour()const {
		int i = 0;
		if (validTour()) {
			if (boardedPass == totalPassengers) {
				cout << "Starting the tour...." << endl;
				cout << "Passenger List:" << endl;
				cout << "|Row | Passenger Name                           | Num |"<<endl;
				cout << "+----+------------------------------------------+-----+" << endl;
				for (i = 0; i < totalPassengers; i++) {
					cout << "|  " << i+1 << " ";
					tourTick[i].display();
					cout << endl;
				}
				cout << "+----+------------------------------------------+-----+" << endl;

			}
			else {
				cout << "Cannot start the tour, the bus is not fully boarded!" << endl;
			}
		}
	}
	TourBus& TourBus::board() {
		int i = 0;
		char tempName[40] = "\0";
		cout << "Boarding "<<totalPassengers<<" Passengers:"<<endl;
		for (i = 0; i < totalPassengers; i++) {
			cout << i + 1 << "/" << totalPassengers << "- Passenger Name: ";
			cin.getline(tempName,40,'\n');
			
			tourTick[i].issue(tempName);
			boardedPass++;
		}

		return *this;
	}
	void TourBus::reset() {
		delete[] tourTick;
		tourTick = nullptr;
		totalPassengers = 0;
		boardedPass = 0;
	}
	TourBus::~TourBus() {
		reset();
	}

};