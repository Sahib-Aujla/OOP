/*
Name:Sahibpreet Singh
Email: sahibpreet-singh1@myseneca.ca
Student ID: 165338211
Date:9 novemeber 2022
Section: NEE
*/
#ifndef SDDS_Dumper_H
#define SDDS_Dumper_H
#include <iostream>
#include "VehicleBasic.h"

namespace sdds
{
	class Dumper :public VehicleBasic {
		double maxCapacity;
		double currCapacity{};
	public:
		Dumper(const char* plate, const int year, const double weight, const char* address);
		bool loaddCargo(double cargo);
		bool unloadCargo();
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std:: istream& in);

	};

	std::ostream& operator<<(std::ostream& os, const Dumper& obj);
	std::istream& operator>>(std::istream& in, Dumper& obj);

	
	
}
#endif

