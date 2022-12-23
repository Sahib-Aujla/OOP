/*
Name: Sahibpreet Singh
student id: 165338211
email: sahibpreet-singh1@myseneca.ca
date: 23 November 2022
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include"Text.h"

namespace sdds {
	Text::Text() {

		m_content = nullptr;
	}
	Text::Text(const Text& obj) {
		m_content = nullptr;
		*this = obj;
	}
	Text& Text::operator=(const Text& obj) {
		if (this != &obj) {
			
			if (obj.m_content != nullptr) {

				if (m_content != nullptr) {
					delete[] m_content;
					m_content = nullptr;
				}

				m_content = new char[strlen(obj.m_content) + 1];
				strcpy(m_content, obj.m_content);
			}
		}
		return *this;
	}
	Text::~Text() {
		delete[] m_content;
		m_content = nullptr;
	}

	const char& Text::operator[](int index)const {

		return m_content[index];
	}
	


	unsigned Text::getFileLength(std::istream& is) {
		unsigned len{};
		if (is) {
			// save the current read position
			std::streampos cur = is.tellg();
			// go to the end
			is.seekg(0, std::ios::end);
			// tell what is the positions (end position = size)
			len = unsigned(is.tellg());
			// now go back to where you were.
			is.seekg(cur);
		}
		return len;
	}
	std::istream& Text::read(std::istream& in) {

		unsigned len = getFileLength(in);
		delete[] m_content;
		m_content = nullptr;
		m_content = new char[len + 1];

		if (in) {
			in.getline(m_content, len+1,EOF);
			
			in.clear();
		}

		return in;
	}
	std::ostream& Text::write(std::ostream& os)const {
		os << m_content;
		return os;
	}

	std::istream& operator>>(std::istream& in, Text& obj) {
		return obj.read(in);
	}
	std::ostream& operator<<(std::ostream& os, const  Text& obj) {
		return obj.write(os);
	}
}