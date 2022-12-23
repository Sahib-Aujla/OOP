/*
Name: Sahibpreet Singh
Student id: 165338211
email: sahibpreet-singh1@myseneca.ca
*/

/* Citation and Sources...
Final Project Milestone 4
Module: Menu
Filename: Menu.cpp
-----------------------------------------------------------
I have done all the coding by myself and used the code
provided in the starter files.
-----------------------------------------------------------*/
#include <iostream>
#include "Motorcycle.h"
#include "Utils.h"

namespace sdds {

	Motorcycle::Motorcycle() {
		sideCar = false;
	}
	Motorcycle::Motorcycle(const char* plate, const char* model):Vehicle(plate,model) {
		sideCar = false;

		}
	Motorcycle::Motorcycle(const Motorcycle& obj){
		*this = obj;
		}
	Motorcycle& Motorcycle::operator = (const Motorcycle& obj){
		if (this != &obj) {
			if (!obj.isEmpty()) {
				(Vehicle&)*this = obj;
				sideCar = obj.sideCar;
			}
		}
		return *this;
	}
	Motorcycle::~Motorcycle(){
		}

	std::ostream& Motorcycle::writeType(std::ostream& os)const{
		(isCsv()) ? os << "M," : os << "Vehicle type: Motorcycle"<<std::endl;
		return os;
	}
	std::ostream& Motorcycle::write(std::ostream& os)const{
		if (isEmpty()) {
			os << "Invalid Motorcycle Object" << std::endl;
		}
		else {
			writeType(os);
			Vehicle::write(os);
			if (isCsv()) {
				os << sideCar << std::endl;

			}
			else {
				if (sideCar) {
					os << "With Sidecar" << std::endl;
				}
			}

		}
		return os;
		}
	std::istream& Motorcycle::read(std::istream& in){
		if (isCsv()) {
			Vehicle::read(in);
			in >> sideCar;
			in.ignore(1000, '\n');
			
		}
		else {
			std::cout << "\nMotorcycle information entry" << std::endl;
			Vehicle::read(in);
			std::cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";
			sideCar= validChar();
		}
		return in;
	}

}