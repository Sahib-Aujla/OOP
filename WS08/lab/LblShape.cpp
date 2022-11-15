#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
#include "LblShape.h"	

using namespace std;

namespace sdds{

	LblShape::LblShape() {
		m_label = nullptr;
	}
	char* LblShape::label()const {
		return m_label;
	}
	void LblShape::allocate(const char*str) {
		if (str != nullptr && strlen(str) > 0) {
			m_label = new char[strlen(str) + 1];
			strcpy(m_label, str);
			
		}
	}

	LblShape::LblShape(const char* str) {
		allocate(str);
	}
	void LblShape::getSpecs(std::istream& in) {
		char temp[100];
		in.getline(temp,100,',');
	
		allocate(temp);

	}

	LblShape::~LblShape() {
		delete[]m_label;
	}
}