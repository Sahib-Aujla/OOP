/*
Name:Sahibpreet Singh
Email: sahibpreet-singh1@myseneca.ca
Student ID: 165338211
Date:9 novemeber 2022
Section: NEE
*/
#ifndef SDDS_VehicleBasic_H
#define SDDS_VehicleBasic_H
#include<iostream>

namespace sdds
{

	class VehicleBasic {
		char licPlate[9];
		char vehicleAddress[64];
		int vehicleYear;
	public:
		VehicleBasic(const char* plate,const int year);
		void NewAddress(const char* address);
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& in);

	};
	std::ostream& operator<<(std::ostream& os,const VehicleBasic& obj);
	std::istream& operator>>(std::istream& in,  VehicleBasic& obj);

}

#endif

