#include<iostream>
#include "Shape.h"

using namespace std;
namespace sdds {

	std::ostream& operator<<(std::ostream& os, const Shape& obj) {
		obj.draw(os);
		return os;
	}
	std::istream& operator>>(std::istream& in, Shape& obj) {
		obj.getSpecs(in);
		return in;
	}
}

