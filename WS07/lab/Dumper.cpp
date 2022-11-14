/*
Name:Sahibpreet Singh
Email: sahibpreet-singh1@myseneca.ca
Student ID: 165338211
Date:9 novemeber 2022
Section: NEE
*/
#include<iostream>
#include "Dumper.h"
#include "VehicleBasic.h"

using namespace std;
namespace sdds
{
	
	Dumper::Dumper(const char* plate, const int year, const double weight, const char* address):VehicleBasic(plate,year) {
		maxCapacity = weight;
		NewAddress(address);
	}
	bool Dumper::loaddCargo(double cargo){
		bool isOK = false;
		if ((cargo + currCapacity)<=maxCapacity) {
			currCapacity += cargo;
			isOK = true;
		}
		return isOK;
	}
	bool Dumper::unloadCargo(){
		bool isOK = false;
		if (currCapacity != 0) {
			currCapacity = 0;
			isOK = true;
		}
		return isOK;
	}
	std::ostream& Dumper::write (std::ostream& os)const{
		VehicleBasic::write(os);
		os << " | " << currCapacity<<"/"<<maxCapacity;
		return os;
	}
	std::istream& Dumper::read(std::istream& in){
		VehicleBasic::read(in);
		cout << "Capacity: ";
		in >> maxCapacity;
		cout << "Cargo: ";
		in >> currCapacity;
		cin.ignore(100, '\n');
		return in;
	}
	std::ostream& operator<<(std::ostream& os, const Dumper& obj) {
		return obj.write(os);
	}
	std::istream& operator>>(std::istream& in, Dumper& obj) {
		return obj.read(in);

	}
	
}

