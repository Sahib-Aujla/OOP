/*
Name: Sahibpreet Singh
Student id: 165338211
email: sahibpreet-singh1@myseneca.ca
*/

/* Citation and Sources...
Final Project Milestone 5
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
	protected:
		void setEmpty();
		
		void setMakeModel(const char*);
	public:
		Vehicle();
		bool isEmpty()const;
		char* getLicensePlate();
		char* getMakeModel()const;
		Vehicle(const char * plate,const char * model);
		Vehicle(const Vehicle&);

		virtual ~Vehicle();
		virtual Vehicle& operator=(const Vehicle&);
		//virtual Vehicle operator=(const Vehicle);


		
		
		int getParkingSpot()const;
		void setParkingSpot(const int spot);

		virtual bool operator==(const Vehicle&)const;
		virtual bool operator==( const char*);
		virtual std::ostream& writeType(std::ostream&)const = 0;
		virtual void setOption(bool is) = 0;
			virtual bool getOption()const = 0;
		virtual std::ostream& write(std::ostream&)const;
		virtual std::istream& read(std::istream&);
	};

}


#endif