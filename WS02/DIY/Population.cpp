/*
Name: Sahibpreet Singh
Student id: 165338211
email: sahibpreet-singh1@myseneca.ca
date of completion: 23 september 2022
*/
#include <cstdio>
#include <iostream>
#include "Population.h"
#include "File.h"
using namespace std;
namespace sdds {
	Population* pop=nullptr;
	int fileCount = 0;
	

	bool load(const char * file) {
		bool isOk= openFile(file);
		
		if (isOk) {
			fileCount=read(pop);
			
		}
		closeFile();
		return isOk;
	}
	void display() {
		int i = 0,totalPop=0;
		cout << "Postal Code: population" << endl;
		cout << "-------------------------" << endl;
		
		sort();
		for (i = 0; i < fileCount; i++) {
			cout << i + 1 << "- " << pop[i].m_code << ":  " << *pop[i].m_pop << endl;
			totalPop += *pop[i].m_pop;
		}
		cout << "-------------------------" << endl;
		cout << "Population of Canada: " << totalPop << endl;
	}
	void deallocateMemory() {
		int i = 0;
		for (i = 0; i < fileCount; i++) {
			delete pop[i].m_pop;
			delete[] pop[i].m_code;
			 pop[i].m_pop=nullptr;
			 pop[i].m_code = nullptr;

		}

		delete[] pop;
		pop = nullptr;

		return;
	}

	void sort() {
		
			int i=0, j=0;
			 Population tempop = {};
			for (i = 0; i < fileCount - 1; i++) {

				for (j = 0; j < fileCount - i - 1; j++)
					if (*pop[j].m_pop > *pop[j + 1].m_pop) {
						tempop = pop[j];
						pop[j] = pop[j + 1];
						pop[j + 1] = tempop;
					}
			}
			tempop = {};
	}
}

