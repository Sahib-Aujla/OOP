/*
Name: Sahibpreet Singh
Student id: 165338211
email: sahibpreet-singh1@myseneca.ca
Date of completion: 21 september 2022
*/
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include "Utils.h"
#include "Assessment.h"

namespace sdds {
	bool read(int& value, FILE* fptr) {
		int check = 0;
		bool isOk = false;
		check=fscanf(fptr, "%d", &value);
		
		if (check > 0) {
			isOk = true;
		}
		return isOk;
	}
	bool read(double& value, FILE* fptr) {
		int check = 0;
		bool isOk = false;
		check = fscanf(fptr, "%lf", &value);
		
		if (check > 0) {
			isOk = true;
		}
		return isOk;
		
	}
	bool read(char* cstr, FILE* fptr) {
		int check = 0;
		bool isOk = false;
		check = fscanf(fptr, ",%60[^\n]\n", cstr);
		
		if (check > 0) {
			isOk = true;
		}
		return isOk;
		
	}
	bool read(Assessment& ass, FILE* fptr) {
		double tempVal=0;
		char tempStr[MAX_CHARS + 1]={};
		
		bool isOk= read(tempVal, fptr);

		bool isOkk= read(tempStr, fptr);
		
		if (isOk && isOkk) {
			int len = strlen(tempStr);
			ass.m_title = new char[len+1];
			strcpy(ass.m_title, tempStr);
			ass.m_mark = new double;
			*ass.m_mark = tempVal;
		
		}

		return isOk && isOkk;
	}
	void freeMem(Assessment*& aptr, int size) {
		int i = 0;
		for ( i = 0; i < size; i++) {
			delete[] aptr[i].m_title;
			delete aptr[i].m_mark;

		}
		delete[] aptr;
		aptr = nullptr;
		return;
	}
	int read(Assessment*& aptr, FILE* fptr) {
		int fileCount = 0, count = 0;;
		read(fileCount, fptr);
		
		if (fileCount) {
			
			aptr = new Assessment[fileCount];
			
			for (int i = 0; i < fileCount; i++) {
				bool isOk = read(aptr[i], fptr);

				if (isOk) {
					count++;
				}
			}

		}
		if (fileCount != count) {
			
			freeMem(aptr, count);
			
			count = 0;
		}

		return count;
	}

};