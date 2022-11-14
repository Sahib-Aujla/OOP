/*
Name: Sahibpreet Singh
Student id: 165338211
email: sahibpreet-singh1@myseneca.ca
date of completion: 23 september 2022
*/
#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
namespace sdds {
	struct Population {
		char* m_code;
		int *m_pop;
	};
	
	bool load(const char* file);
	void display();
	void deallocateMemory();
	void sort();
};
#endif 