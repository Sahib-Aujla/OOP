#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H

#include "Shape.h"

namespace sdds {

	class LblShape :public Shape {
		char* m_label;
		void allocate(const char*);
	protected:
		char* label()const;
	public:
		LblShape();
		LblShape(const char* str);
		LblShape(const LblShape&) = delete;
		LblShape& operator=(const LblShape&) = delete;
		void getSpecs(std::istream&);
		

		~LblShape();
	};

};


#endif