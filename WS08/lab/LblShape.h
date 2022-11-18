/*
Name: Sahibpreet Singh
email: sahibpreet-singh1@myseneca.ca
Student id: 165338211
Date: 14 november 2022
*/
#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H

#include "Shape.h"

namespace sdds {

	class LblShape :public Shape {
		char* m_label{nullptr};
		void allocate(const char*);
	protected:
		char* label()const;
	public:
		LblShape();
		LblShape(const char* str);
		LblShape(const LblShape&) = delete;
		LblShape& operator=(const LblShape&) = delete;
		void getSpecs(std::istream&);
		

		virtual ~LblShape();
	};

};


#endif