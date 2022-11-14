/*
Name: Sahibpreet Singh
email: sahibpreet-singh1@myseneca.ca
student id: 165338211
date of completion: 18 september 2022
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include "word.h"
#include "dictionary.h"
namespace sdds {
	int findEmptyIndex(int flagType, int wordIndex,struct Word* singleWord) {
		int flag = 0, i = 0, index = -1;
		if (flagType == 1) {
			while (flag == 0 && i < MAXWORDS) {
				if (strlen(singleWord[i].word) == 0) {
					flag = 1;
					index = i;
				}
				i++;
			}
		}
		else {
			while (flag == 0 && i < MAXDEFINTION) {
				if (strlen(singleWord[wordIndex].definition[i]) == 0) {
					flag = 1;
					index = i;
				}
				i++;
			}
		}
		return index;
	}

	void setToOverwrite(struct Word* singleWord,int totalWordCount) {
		for (int i = 0; i < totalWordCount; i++) {
			strcpy(singleWord[i].word, "\0");
			singleWord[i].defintionCount = 0;
		}
	}

	int findIndex(const char* word,struct Word* singleWord,int totalWordCount) {
		int index = -1, i = 0;
		for (i = 0; i < totalWordCount; i++) {
			if (strcmp(word, singleWord[i].word) == 0) {
				index = i;
			}
		}
		return index;
	}
}