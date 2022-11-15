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
