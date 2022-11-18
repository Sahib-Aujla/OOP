/*
Name: Sahibpreet Singh
email: sahibpreet-singh1@myseneca.ca
Student id: 165338211
Date: 14 november 2022
*/
#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H
#include <iostream>
namespace sdds {

	class Shape {
	public:
		virtual void draw(std::ostream&)const =0;
		virtual void getSpecs(std::istream&) = 0;
		virtual  ~Shape(){};
		
	};

	std::ostream& operator<<(std::ostream& os, const Shape& obj);
	std::istream& operator>>(std::istream& in, Shape& obj);



};

#endif
