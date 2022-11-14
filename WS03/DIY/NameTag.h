/*
Name: Sahibpreet Singh
Student id: 165338211
email: sahibpreet-singh1
date of submission: 30/09/2022
*/
#ifndef SDDS_NAMETAG_H
#define SDDS_NAMETAG_H

namespace sdds {
	class NameTag {
		char nametag[51];
	public:
		void set(const char* name);
		int countTheLongest();
		void printName(int len);
	};
}

#endif