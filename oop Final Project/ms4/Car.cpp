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
#include "Car.h"
#include "Utils.h"

namespace sdds {
	Car::Car(){
		carWash = false;
		}
	Car::Car(const char* plate, const char* model):Vehicle(plate,model) {

		}
	Car::Car(const Car& obj){
		*this = obj;
		}
	Car& Car::operator=(const Car& obj){
		if (this != &obj) {
			if (!obj.isEmpty()) {
				(Vehicle&)*this = obj;
				carWash = obj.carWash;
			}
		}
		return *this;
	}
	std::ostream& Car::writeType(std::ostream& os)const{
		if (isCsv()) {
			os << "C,";
		}
		else {
			os << "Vehicle type: Car" << std::endl;
		}
		return os;
		}
	std::ostream& Car::write(std::ostream& os)const{
		if (isEmpty()) {
			os << "Invalid Car Object" << std::endl;
		}
		else {
			writeType(os);
			Vehicle::write(os);

			if (isCsv()) {
			
			
				os << carWash<<std::endl;
			}
			else {
				

				(carWash) ? (os << "With Carwash") : os << "Without Carwash";
				os<<std::endl;
			}
		}
		return os;

	}
	std::istream& Car::read(std::istream& in) {
	
		if (isCsv()) {
			Vehicle::read(in);
				
				in >> carWash;
				in.ignore(1000, '\n');
				
		}
		else {
			std::cout << "\nCar information entry" << std::endl;
			Vehicle::read(in);
			std::cout << "Carwash while parked? (Y)es/(N)o: ";
			carWash = validChar();
		}
		return in;
	}
	Car::~Car() {
		
	}


}