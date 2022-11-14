/*
Name:Sahibpreet Singh
Email: sahibpreet-singh1@myseneca.ca
Student ID: 165338211
Date:9 novemeber 2022 
Section: NEE
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "VehicleBasic.h"

using namespace std;

namespace sdds
{
	
	VehicleBasic::VehicleBasic(const char* plate, const int year) {
		strncpy(licPlate, plate, 8);
		strncpy(vehicleAddress, "Factory", 63);
		vehicleYear = year;
	}
	void VehicleBasic::NewAddress(const char* address){
		if (strcmp(address, vehicleAddress) != 0) {
			cout.setf(ios::right);
			
			cout << "|";
			cout.width(8);
			cout<< licPlate;
			cout << "| |";
			cout.width(20);

			cout << vehicleAddress;
			strncpy(vehicleAddress, address, 63);

			cout<< " ---> ";
			cout.unsetf(ios::right);
			cout.setf(ios::left);
			cout.width(20);
			cout << vehicleAddress;
			cout<< "|" << endl;
			cout.unsetf(ios::right);
		}
	}
	std::ostream& VehicleBasic::write(std::ostream& os)const {
		os << "| " << vehicleYear << " | " << licPlate << " | " << vehicleAddress;
		return os;
	}
	std::istream& VehicleBasic::read(std::istream& in){
		cout << "Built year: ";
		in >> vehicleYear;
		cout << "License plate: ";
		in >> licPlate;
		cout << "Current location: ";
		
		in >> vehicleAddress;
		in.ignore(1000, '\n');
		return in;
	}
	ostream& operator<<(std::ostream& os,const  VehicleBasic& obj) {
		return obj.write(os);
	}
	istream& operator>>(std::istream& in, VehicleBasic& obj) {
		return obj.read(in);
	}
	
}
