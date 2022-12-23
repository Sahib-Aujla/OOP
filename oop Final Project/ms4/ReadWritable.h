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
#ifndef SDDS_READWRITABLE_H
#define SDDS_READWRITABLE_H
#include<iostream>
namespace sdds {

	class ReadWritable {
		bool comaFormat;
	public:
		ReadWritable();

		ReadWritable(const ReadWritable&);

		virtual ~ReadWritable() {};
		bool isCsv() const;
		void setCsv(bool value);
		
		virtual std::ostream& write(std::ostream& )const = 0;
		virtual std::istream& read(std::istream& ) = 0;
		
	};
	std::istream& operator>>(std::istream& in, ReadWritable& obj);
	std::ostream& operator<<(std::ostream& os, const ReadWritable& obj);
}

#endif