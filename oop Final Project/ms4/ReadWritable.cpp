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
#include"ReadWritable.h"

namespace sdds {

	ReadWritable::ReadWritable() {
		comaFormat = false;
	}
	ReadWritable::ReadWritable(const ReadWritable& obj) {
		this->comaFormat = obj.comaFormat;
	}

	bool ReadWritable::isCsv() const {
		return comaFormat;
	}
	void ReadWritable::setCsv(bool value) {
		comaFormat = value;
	}

	std::istream& operator>>(std::istream& in, ReadWritable& obj) {
		return obj.read(in);
	}
	std::ostream& operator<<(std::ostream& os, const ReadWritable& obj) {
		return obj.write(os);
	}
}