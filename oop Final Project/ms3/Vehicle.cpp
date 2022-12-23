/*
Name: Sahibpreet Singh
Student id: 165338211
email: sahibpreet-singh1@myseneca.ca
*/

/* Citation and Sources...
Final Project Milestone 3
Module: Menu
Filename: Menu.cpp
-----------------------------------------------------------
I have done all the coding by myself and used the code
provided in the starter files.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>
#include"Vehicle.h"
#include "Utils.h"
namespace sdds {
	
	Vehicle::Vehicle() {
		setEmpty();
	}
	Vehicle::Vehicle(const char* plate,const char* model) {
		if (plate != nullptr && model != nullptr && strlen(model)>=2 && strlen(plate)<=8) {
			strncpy(licPlate, plate, 8);
			toUpperCase(licPlate);
			
			setMakeModel(model);
			parkSpotNum = 0;
		}
		else {
			setEmpty();
		}
	}
	Vehicle::~Vehicle() {
		setEmpty();

	}

	Vehicle::Vehicle(const Vehicle& obj) {
		 *this = obj;
	}


	Vehicle& Vehicle::operator=(const Vehicle& obj) {
		if (this != &obj) {
			if (!obj.isEmpty()) {
				strcpy(licPlate, obj.licPlate);
				setParkingSpot(obj.parkSpotNum);
				setMakeModel(obj.make_Model);

			}
		}
		return *this;
	}

	void Vehicle::setEmpty() {
		
		strcpy(licPlate, "\0");
		delete[] make_Model;
		make_Model = nullptr;
		parkSpotNum = 0;
	}

	bool Vehicle::isEmpty()const {
		
		return licPlate[0] == '\0';
	}
	char* Vehicle::getLicensePlate() {
	
		return licPlate;
	}
	char* Vehicle::getMakeModel()const{
		return make_Model;
		}
	void Vehicle::setMakeModel(const char* model){
		if (model != nullptr && strlen(model) >= 2) {
			delete[] make_Model;
			make_Model = new char[strlen(model) + 1];
			strcpy(make_Model, model);
		}
		else {
			setEmpty();
		}
	}
	int Vehicle::getParkingSpot()const{
		return parkSpotNum;
		}
	void Vehicle::setParkingSpot(const int spot){
		if (spot >= 0) {
			parkSpotNum = spot;
		}
		else {
			setEmpty();
		}
		
		}
	bool Vehicle::operator == (const Vehicle& obj)const{
		char temp[8], temp2[8];
		bool isOk = false;
		

		if (!isEmpty() && !obj.isEmpty()) {
			strcpy(temp, licPlate);
			strcpy(temp2, obj.licPlate);
			toUpperCase(temp);
			toUpperCase(temp2);

			int res=strcmp(temp, temp2);
			if (res == 0) {
				isOk = true;
			}
		}
		return isOk;


	}
	bool Vehicle::operator==(const char* str) {
		char temp[8]{}, temp2[8]{};
		bool isOk = false;
		
		
		if (!isEmpty() ) {
			

			strcpy(temp, getLicensePlate());
			strcpy(temp2, str);
			
			
			toUpperCase(temp);
			toUpperCase(temp2);
			

			int res = strcmp(temp, temp2);
			

			if (res == 0) {

				isOk = true;
			}

		}
		return isOk;
	}
	std::ostream& Vehicle::write(std::ostream& os)const{
		
		if (isEmpty()) {
			
			os << "Invalid Vehicle Object" << std::endl;
		}
		else {
			if (isCsv()) {
				os <<"T," << parkSpotNum << "," << licPlate << "," << make_Model << ",";
			}
			else {
				os << "T,Parking Spot Number: ";
				(parkSpotNum > 0) ? (os  << parkSpotNum << std::endl) : os << "N/A" << std::endl;
				os << "License Plate: "<<licPlate<<std::endl;
				

				os << "Make and Model: " << make_Model << std::endl;
				
			}
		}
		return os;
		}
	std::istream& Vehicle::read(std::istream& in){
		if (isCsv()) {
			char temp[61];
			in >> parkSpotNum;
			in.ignore();
			in.getline(licPlate, 8, ',');
			toUpperCase(licPlate);
			in.getline(temp, 60, ',');
			setMakeModel(temp);
		}
		else {
			std::cout << "Enter License Plate Number: ";
			bool done = false;

			do {
				in.getline(licPlate, 8);
				if (in.fail()) {
					std::cout << "Invalid License Plate, try again: ";
					in.clear();
					in.ignore(100, '\n');
				}
				else {
					done = true;
				toUpperCase(licPlate);
				}
			} while (!done);

			 done = false;
			std::cout << "Enter Make and Model: ";
			char temp1[61];
			while (!done) {
				in.getline(temp1, 60);
				
				if (!in.fail() && strlen(temp1) >= 2) {
					setMakeModel(temp1);
					done = true;
				}
				else {
					std::cout << "Invalid Make and model, try again: ";
				}
			}
			parkSpotNum = 0;

		}
		return in;
		}
}