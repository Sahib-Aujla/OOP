/*
Name: Sahibpreet Singh
email: sahibpreet-singh1@myseneca.ca
Student id: 165338211
Date: 14 november 2022
*/
#include<iostream>
#include "Shape.h"

using namespace std;
namespace sdds {

	std::ostream& operator<<(std::ostream& os, const Shape& obj) {
		obj.draw(os);
		return os;
	}
	std::istream& operator>>(std::istream& in, Shape& obj) {
		obj.getSpecs(in);
		return in;
	}

}

