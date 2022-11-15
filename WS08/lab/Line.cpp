#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Line.h"

using namespace std;

namespace sdds {

	Line::Line():LblShape() {
		m_length = 0;
	}
	Line::Line(const char* str,const int len):LblShape(str) {
		if (len > 0) {
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
			int labelLen = strlen(label());
			int remainingWidth = m_length;
			os << label();
			remainingWidth -= labelLen;
			for (int i = 0; i < remainingWidth; i++) {
				os << "=";
			}
		}
	}
}