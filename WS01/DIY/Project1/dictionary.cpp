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
#include "dictionary.h"
#include "word.h"
using namespace std;


namespace sdds {
	Word singleWord[MAXWORDS];

	int totalWordCount = 0;
	char c;

	int LoadDictionary(const char* filename) {
		FILE* fileptr = fopen(filename, "r");
		int isNull = fileptr == nullptr;
		int i = 0, j = 0;
		char c;
		int ok = 0;
		if (!isNull) {
			
			while (!feof(fileptr)) {
				
				ok = fscanf(fileptr, "%s", singleWord[i].word);
				fgetc(fileptr);
				if (ok > 0) {
					
					c = fgetc(fileptr); 
					 j = 0;
					while (c == '\t') {
				
						fscanf(fileptr, "%[^:]: %[^\n]", singleWord[i].type[j], singleWord[i].definition[j]);
						
						singleWord[i].defintionCount++;
						fgetc(fileptr);
						j++;
						c = fgetc(fileptr);

					}
				}
				
				totalWordCount++;

				
				i++;
			};
			fclose(fileptr);
		}
		
		return isNull;
	}

	void SaveDictionary(const char* filename) {
		FILE* fileptr = fopen(filename, "w");
		
		for (int i = 0; i < totalWordCount; i++) {
			fprintf(fileptr, "%s", singleWord[i].word);
			fputc('\n', fileptr);
			for (int j = 0; j < singleWord[i].defintionCount; j++) {
				fprintf(fileptr, "\t%s: %s\n", singleWord[i].type[j], singleWord[i].definition[j]);
			}
			fputc('\n', fileptr);
		}
		fclose(fileptr);
		setToOverwrite(singleWord,totalWordCount);
		return;
	}
	void DisplayWord(const char* word) {
		int index = -1,i=0;
		index = findIndex(word,singleWord, totalWordCount);
		if (index != -1) {
			cout << "FOUND: [" << singleWord[index].word << "] has [" << singleWord[index].defintionCount << "] definitions:" << endl;
			for (i = 0; i < singleWord[index].defintionCount; i++) {
				cout << i + 1 << ". {" << singleWord[index].type[i] << "} " << singleWord[index].definition[i] << endl;
			}
		}
		else {
			cout << "NOT FOUND: word ["<<word<<"] is not in the dictionary." << endl;
		}

		return;
	}
	void AddWord(const char* word, const char* type, const char* definition) {
		int index = -1, emptyIndexWord=-1;
		index = findIndex(word,singleWord, totalWordCount);

		if (index == -1) {
			
			 emptyIndexWord=findEmptyIndex(1,0,singleWord);

			 index = emptyIndexWord;
			 strcpy(singleWord[index].word, word);
			
			 totalWordCount++;
		}
		emptyIndexWord = findEmptyIndex(0, index,singleWord);

		
		strcpy(singleWord[index].type[emptyIndexWord], type);
		strcpy(singleWord[index].definition[emptyIndexWord], definition);
		
		singleWord[index].defintionCount++;
		return;
	}
	int UpdateDefinition(const char* word, const char* type, const char* definition) {
		int i = 0,index=-1;
		index = findIndex(word,singleWord, totalWordCount);

		if (index != -1) {
			
			if (singleWord[index].defintionCount > 1) {
				cout << "The word [" << word << "] has multiple definitions:" << endl;
				for (i = 0; i < singleWord[index].defintionCount; i++) {
					cout << i + 1 << ". {" << singleWord[index].type[i] << "} " << singleWord[index].definition[i] << endl;
				}
				cout << "Which one to update? ";
				cin >> i;
				i--;
			}
			else {
				cout << "The word [" << word << "] has single definition:" << endl;
				i = 0;
			}
			strcpy(singleWord[index].type[i], type);
			strcpy(singleWord[index].definition[i], definition);
			
		}

		return 0;
	}
};