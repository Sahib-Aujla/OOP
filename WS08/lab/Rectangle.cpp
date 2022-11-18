/*
Name: Sahibpreet Singh
email: sahibpreet-singh1@myseneca.ca
Student id: 165338211
Date: 14 november 2022
*/
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>

#include "Rectangle.h"

namespace sdds {

	Rectangle::Rectangle():LblShape() {
		m_width = 0;
		m_height = 0;
	}
	Rectangle::Rectangle(const char* str, const int width, const int height):LblShape(str) {
		int temp = (strlen(label()) + 2);
		if (height >= 3 && temp <width && label()!=nullptr) {
			m_width = width;
			m_height = height;
		}
		else {

			m_width = 0;
			m_height = 0;
		}
	}
	void Rectangle::getSpecs(std::istream& in) {
		LblShape::getSpecs(in);
		in >> m_width;
		in.ignore();
		in >> m_height;
		in.ignore(1000, '\n');
	}
	void Rectangle::draw(std::ostream& os) const {
		if (m_width != 0) {
			for (int i = 0; i < m_height; i++) {
				if (i == 0 || i == m_height - 1) {
					os << "+";					
					os.setf(std::ios::left);
					os.width(m_width - 1);
					os.fill('-');
					os.unsetf(std::ios::left);
					os << "+";
					if (i == 0) {
						os << std::endl;
					}
				}
				else if (i == 1) {
					os << "|" ;
					os.setf(std::ios::left);
					os.width(m_width-2);
					os.fill(' ');
					os << label();
					os.unsetf(std::ios::left);	
					os << "|" << std::endl;
				}
				else {
					os << "|" ;	
					os.setf(std::ios::left);
					os.width(m_width - 1);
					os.fill(' ');
					os.unsetf(std::ios::left);
					os << "|"<<std::endl ;
				}
			}
		}
	}
}