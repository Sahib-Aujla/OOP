/*
Name: Sahibpreet Singh
Student id: 165338211
email: sahibpreet-singh1@myseneca.ca
Date of completion: 21 september 2022
*/

#ifndef SDDS_ASSESSMENT_H
#define SDDS_ASSESSMENT_H

namespace sdds {
	struct Assessment {
		double* m_mark;
		char* m_title;
	};
	const int MAX_CHARS = 60;
	bool read(int& value, FILE* fptr);
	bool read(double& value, FILE* fptr);
	bool read(char* cstr, FILE* fptr);
	bool read(Assessment& ass, FILE* fptr);
	void freeMem(Assessment*& aptr, int size);
	int read(Assessment*& aptr, FILE* fptr);
};
#endif

