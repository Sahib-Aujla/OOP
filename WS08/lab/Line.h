/*
Name: Sahibpreet Singh
email: sahibpreet-singh1@myseneca.ca
Student id: 165338211
Date: 14 november 2022
*/
#ifndef SDDS_LINE_H
#define SDDS_LINE_H
#include "LblShape.h"

namespace sdds {

	class Line :public LblShape {
		int m_length{};
	public:
		Line();
		Line(const char* str,const int len);
		void getSpecs(std::istream&);
		void draw(std::ostream&) const;
	};
}


#endif
