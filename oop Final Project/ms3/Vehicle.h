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

#ifndef SDDS_VEHICLE_H
#define SDDS_VEHICLE_H

#include "ReadWritable.h"

namespace sdds {

	class Vehicle:public ReadWritable {
		char licPlate[9]{};
		char* make_Model{};
		int parkSpotNum{};
	public:
		Vehicle();

		Vehicle(const char * plate,const char * model);
		Vehicle(const Vehicle&);

		virtual ~Vehicle();
		virtual Vehicle& operator=(const Vehicle&);

		void setEmpty();
		bool isEmpty()const;
		 char* getLicensePlate();
		char* getMakeModel()const;
		void setMakeModel(const char *);
		int getParkingSpot()const;
		void setParkingSpot(const int spot);

		virtual bool operator==(const Vehicle&)const;
		virtual bool operator==( const char*);
		virtual std::ostream& writeType(std::ostream&)const = 0;
		 std::ostream& write(std::ostream&)const;
		 std::istream& read(std::istream&) ;
	};

}


#endif