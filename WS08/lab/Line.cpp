/*
Name: Sahibpreet Singh
email: sahibpreet-singh1@myseneca.ca
Student id: 165338211
Date: 14 november 2022
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Line.h"

using namespace std;

namespace sdds {

	Line::Line():LblShape() {
		m_length = 0;
	}
	Line::Line(const char* str,const int len):LblShape(str) {
		if (len > 0 && label()!=nullptr) {
			m_length = len;
		}
	}
	void Line::getSpecs(std::istream& in) {
		
		LblShape::getSpecs(in);
		
		in >> m_length;
		
		in.ignore(1000, '\n');
	}
	void Line::draw(std::ostream& os) const {
		if (m_length > 0 && label() != nullptr) {
			
			os.setf(ios::left);
			os.width(m_length);
			os.fill('=');
			os << label();
			os.unsetf(ios::left);

			
		}
	}
}