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
		if (height >= 3 && (strlen(label()) + 2)<width) {
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
					for (int j = 0; j < m_width - 2; j++) {
						os << "-";
					}
					os << "+" << std::endl;
				}
				else if (i == 1) {
					os << "|" << label();
					int remaingWidth = m_width - strlen(label()) - 2;
					for (int j = 0; j < remaingWidth; j++) {
						os << " ";
					}
					os << "|" << std::endl;
				}
				else {
					os << "|" ;

					for (int j = 0; j < m_width-2; j++) {
						os << " ";
					}
					os << "|" << std::endl;

				}
			}
		}
	}
}