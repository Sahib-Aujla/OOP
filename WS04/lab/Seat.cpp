/*
Name: Sahibpreet Singh
student id: 165338211
email: sahibpreet-singh1@myseneca.ca
Date of completion: 4 sept 2022
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Seat.h"
using namespace std;
namespace sdds {
	bool Seat::validate(int row, char letter)const {
		bool isOk=false;

		if (row >= 1 && row <= 4) {
			if (letter == 'A' || letter == 'B' || letter == 'E' || letter == 'F') isOk = true;
		}
		else if ((row >= 7 && row <= 15) || (row >= 20 && row <= 38)) {
			if (letter == 'A' || letter == 'B' || letter=='C' || letter=='D' || letter == 'E' || letter == 'F') isOk = true;

		}

		return isOk;
	}
	Seat& Seat::alAndCp(const char* str) {
		passengerName = nullptr;
		reset();
		if (str != nullptr) {
			passengerName = new char[strlen(str) + 1];
			strcpy(passengerName, str);
		}
		return *this;
	}

	Seat::Seat() {
		passengerName = nullptr;
		reset();
	}
	Seat::Seat(const char* passengerName) {
		alAndCp(passengerName);
		row_no = 0;
		seat_letter = '\0';
	}
	Seat::Seat(const char* passengerName, int row, char letter) {
		alAndCp(passengerName);
		set(row, letter);
	}


	Seat& Seat::reset() {
		delete[] passengerName;
		passengerName = nullptr;
		row_no = 0;
		seat_letter = '\0';

		return *this;
	}

	bool Seat::isEmpty() const {
		return passengerName==nullptr;
	}
	bool Seat::assigned() const {
		bool isOkk = passengerName != nullptr;
		bool isOk = validate( row_no, seat_letter);

		return isOkk && isOk;
	}
	Seat& Seat::set(int row, char letter) {
		bool isOk = validate(row, letter);
		if (isOk == true) {
			row_no = row;
			seat_letter = letter;
		}
		else {
			row_no = 0;
			seat_letter = '\0';
		}
		return *this;
	}
	int Seat:: row()const {
		return row_no;
	}
	char Seat::letter()const {
		return seat_letter;
	}
	const char* Seat::passenger()const {
		return passengerName;
	}


	//input/output
	std::ostream& Seat::display(std::ostream& coutRef )const {
		if (!isEmpty() && strlen(passengerName)>0) {
			coutRef.setf(std::ios::left); 
			if (strlen(passengerName) > 40) coutRef.write(passengerName, 40);
			else {
				coutRef.width(40);
				coutRef.fill('.');
				coutRef << passengerName;
				coutRef.fill(' ');

			}
			coutRef.unsetf(std::ios::left);

			if (row_no != 0) {
				coutRef << " " << row_no << seat_letter;
			}
			else {
				coutRef << " ___";
			}
		}
		else {
			coutRef << "Invalid Seat!";
		}

		return coutRef;
	}
	std::istream& Seat::read(std::istream& cinRef ) {
		char str[71]{};
		int row = 0;
		char letter{};


		
		reset();
		//cinRef.ignore();
		cinRef.getline(str,70,',');
		
		cinRef >> row>> letter;
		cinRef.ignore();

		if (cinRef.fail()==false) {
			
			alAndCp(str);
			if (passengerName != nullptr) {
				set(row, letter);
			}
		}

		return cinRef;
	}

	Seat::~Seat() {
		reset();
	}
	
}