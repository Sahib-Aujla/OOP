/*
Name: Sahibpreet Singh
Student id: 165338211
email: sahibpreet-singh1
date of submission: 30/09/2022
*/
#ifndef SDDS_TAGLIST_H
#define SDDS_TAGLIST_H
#include "NameTag.h"

namespace sdds{
	class TagList {
		NameTag* namTag;
		int index=0;
		int maxLen = 0;
	public:
		void set();
		void set(int num);
		void add(const NameTag& nt);
		void print();
		void cleanup();
		
	};
}

#endif // !SDDS_TAGLIST_H
