/*
Name: Sahibpreet Singh
Student id: 165338211
email: sahibpreet-singh1
date of submission: 30/09/2022
*/
#include <iostream>
#include  "Utils.h"
#include "NameTag.h"
#include "TagList.h"

namespace sdds {
	void TagList::set() {
		
		namTag = nullptr;
		index = 0;
		maxLen = 0;
	}
	void TagList::set(int num) {
		cleanup();
		if (namTag == nullptr) {
			namTag = new NameTag[num];

		}
	}
	void TagList::add(const NameTag& nt) {
		int len = 0;
		namTag[index] = nt;
		len=namTag[index].countTheLongest();
		if (len > maxLen) {
			maxLen = len;
		}
		index++;
	}
	void TagList::print() {
		int i = 0;
		for (i = 0; i < index; i++) {
			namTag[i].printName(maxLen);
		}
	}
	void TagList::cleanup() {
		delete[] namTag;
		set();

	}
	

}