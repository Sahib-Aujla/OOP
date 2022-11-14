/*
Name: Sahibpreet Singh
email: sahibpreet-singh1@myseneca.ca
student id: 165338211
date of completion: 18 september 2022
*/
#ifndef SDDS_WORD_H
#define SDDS_WORD_H

namespace sdds {
	int findEmptyIndex(int flagType, int wordIndex,struct Word* singleWord);
	void setToOverwrite(struct Word* singleWord,int totalWordCount);
	int findIndex(const char* word,struct Word* singleWord,int totalWordCount);
}

#endif