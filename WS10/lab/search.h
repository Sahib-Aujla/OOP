/*
Name: Sahibpreet Singh
Student id:165338211
email:sahibpreet-singh1@myseneca.ca
date: 28 november 2022
*/

#ifndef SDDS_SEARCH_H
#define SDDS_SEARCH_H

#include "Collection.h"


namespace sdds {
	template <typename T>
	bool search(const T arr[],const int size,const char* str,Collection<T>& obj) {
		bool isOk = false;
		int i = 0;
		for (i = 0; i < size; i++) {
			
			if (arr[i] == str) {
				
				obj.add(arr[i]);
				isOk = true;
			}

			
		}
		return isOk;
	}

}

#endif