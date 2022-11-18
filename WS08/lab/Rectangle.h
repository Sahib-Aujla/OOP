/*
Name: Sahibpreet Singh
email: sahibpreet-singh1@myseneca.ca
Student id: 165338211
Date: 14 november 2022
*/
#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H

#include "LblShape.h"

namespace sdds {
	class Rectangle :public LblShape {
		int m_width;
		int m_height;

	public:
		Rectangle();
		Rectangle(const char* str, const int width, const int height);
		void getSpecs(std::istream&);
		void draw(std::ostream&) const;

	};
}

#endif
