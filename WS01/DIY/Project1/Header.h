#pragma once
//#include <iostream>
//using namespace std;
//namespace sdds {
//	const int MAXWORDS = 100;
//	const int MAXDEFINTION = 8;
//	const int MAXDEFINTIONCHARACTER = 1024;
//	const int MAXTYPECHARACTER = 64;
//
//	struct Word {
//		char word[65];
//		int defintionCount = 0;
//		char type[MAXDEFINTION][MAXTYPECHARACTER];
//		char definition[MAXDEFINTION][MAXDEFINTIONCHARACTER];
//	};
//	/*struct Dictionary {
//		char words[100][100];
//		int count=0;
//	};*/
//
//	int LoadDictionary(const char* filename);
//	void SaveDictionary(const char* filename);
//	void DisplayWord(const char* word);
//	void AddWord(const char* word, const char* type, const char* definition);
//	int UpdateDefinition(const char* word, const char* type, const char* definition);
//	int findEmptyIndex(int flagType, int wordIndex);
//	void setToOverwrite();
//	int findIndex(const char* word);
//
//};



//#pragma once
//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//#include <cstdio>
//#include "dictionary.h"
//
//using namespace std;
//
//namespace sdds {
//	Word singleWord[MAXWORDS];
//
//	int totalWordCount = 0;
//	char c;
//
//	int LoadDictionary(const char* filename) {
//		FILE* sfptr = fopen(filename, "r");
//		int isNull = sfptr == nullptr;
//		int i = 0, j = 0;
//		char c;
//		int ok = 0;
//		if (!isNull) {
//
//			while (!feof(sfptr)) {
//
//				ok = fscanf(sfptr, "%s", singleWord[i].word);
//				fgetc(sfptr);
//				if (ok > 0) {
//
//					c = fgetc(sfptr);
//					j = 0;
//					while (c == '\t') {
//
//
//						fscanf(sfptr, "%[^:]: %[^\n]", singleWord[i].type[j], singleWord[i].definition[j]);
//
//						singleWord[i].defintionCount++;
//						fgetc(sfptr);
//						j++;
//						c = fgetc(sfptr);
//
//					}
//				}
//
//				totalWordCount++;
//
//
//				i++;
//			};
//			fclose(sfptr);
//		}
//
//		return isNull;
//	}
//
//	void SaveDictionary(const char* filename) {
//		FILE* sfptr = fopen(filename, "w");
//
//		for (int i = 0; i < totalWordCount; i++) {
//			fprintf(sfptr, "%s", singleWord[i].word);
//			fputc('\n', sfptr);
//
//			for (int j = 0; j < singleWord[i].defintionCount; j++) {
//				fprintf(sfptr, "\t%s: %s\n", singleWord[i].type[j], singleWord[i].definition[j]);
//
//
//			}
//			fputc('\n', sfptr);
//		}
//		fclose(sfptr);
//		setToOverwrite();
//		return;
//	}
//	void DisplayWord(const char* word) {
//		int index = -1, i = 0;
//		index = findIndex(word);
//		if (index != -1) {
//			cout << "FOUND: [" << singleWord[index].word << "] has [" << singleWord[index].defintionCount << "] defintiions:" << endl;
//			for (i = 0; i < singleWord[index].defintionCount; i++) {
//				cout << i + 1 << ". {" << singleWord[index].type[i] << "} " << singleWord[index].definition[i] << endl;
//			}
//		}
//		else {
//			cout << "NOT FOUND: word [" << word << "] is not in the dictionary." << endl;
//		}
//
//		return;
//	}
//	void AddWord(const char* word, const char* type, const char* definition) {
//		int i = 0, index = -1, emptyIndexWord = -1;
//		index = findIndex(word);
//
//		if (index == -1) {
//
//			emptyIndexWord = findEmptyIndex(1, 0);
//
//			index = emptyIndexWord;
//			strcpy(singleWord[index].word, word);
//
//			totalWordCount++;
//		}
//		emptyIndexWord = findEmptyIndex(0, index);
//
//
//		strcpy(singleWord[index].type[emptyIndexWord], type);
//		strcpy(singleWord[index].definition[emptyIndexWord], definition);
//
//		singleWord[index].defintionCount++;
//		return;
//	}
//	int UpdateDefinition(const char* word, const char* type, const char* definition) {
//		int i = 0, index = -1;
//		index = findIndex(word);
//
//		if (index != -1) {
//
//			if (singleWord[index].defintionCount > 1) {
//				cout << "The word [" << word << "] has multiple definitions:" << endl;
//				for (i = 0; i < singleWord[index].defintionCount; i++) {
//					cout << i + 1 << ". {" << singleWord[index].type[i] << "} " << singleWord[index].definition[i] << endl;
//				}
//				cout << "Which one to update? ";
//				cin >> i;
//				i--;
//			}
//			else {
//				cout << "The word [" << word << "] has single definition:" << endl;
//				i = 0;
//			}
//			strcpy(singleWord[index].type[i], type);
//			strcpy(singleWord[index].definition[i], definition);
//
//		}
//
//		return 0;
//	}
//
//
//	int findEmptyIndex(int flagType, int wordIndex) {
//		int flag = 0, i = 0, index = -1;
//		if (flagType == 1) {
//			while (flag == 0 && i < MAXWORDS) {
//				if (strlen(singleWord[i].word) == 0) {
//					flag = 1;
//					index = i;
//				}
//				i++;
//			}
//		}
//		else {
//			while (flag == 0 && i < MAXDEFINTION) {
//				if (strlen(singleWord[wordIndex].definition[i]) == 0) {
//					flag = 1;
//					index = i;
//				}
//				i++;
//			}
//		}
//		return index;
//	}
//
//	void setToOverwrite() {
//		for (int i = 0; i < totalWordCount; i++) {
//			strcpy(singleWord[i].word, "\0");
//			singleWord[i].defintionCount = 0;
//		}
//	}
//
//	int findIndex(const char* word) {
//		int index = -1, i = 0;
//		for (i = 0; i < totalWordCount; i++) {
//			if (strcmp(word, singleWord[i].word) == 0) {
//				index = i;
//			}
//		}
//		return index;
//	}
//};
//
//
//
//
////
////int i = 0;
////while (!feof(sfptr)) {
////	int j = 0;
////	fscanf(sfptr, "%[^\n]", singleWord[i].word);
////	//printf("%s khdk", singleWord[i].word);
////	cout << "hahah  " << singleWord[i].word << endl;
////	//fscanf(sfptr, "%[\t]", c);
////	/*c = fgetc(sfptr);
////	cout << c << "tab" << endl;*/
////	c = fgetc(sfptr);
////	cout << c << "tab" << endl;
////	if (c == '\t') {
////		fscanf(sfptr, "%[^:]:%[^\n]", singleWord[i].type[0], singleWord[i].definition[0]);
////		cout << singleWord[i].type[0] << "  lol   " << singleWord[i].definition[0] << endl;
////	}
////	//cout << c << "before" << endl;
////	c = fgetc(sfptr);
////	/*cout << c << "between" << endl;
////
////	c = fgetc(sfptr);
////	cout << c << "after" << endl;*/
////	if (c == '\n') {
////		printf("if statement\n");
////		break;
////	}
////	i++;
////}
//
//
////	int i = 0;
//		//	while (!feof(sfptr)) {
//		//		c = fgetc(sfptr);
//		//		//printf("%c", c);
//		//		
//		//		while (c != '\n') {
//		//			if (c == '\t') {
//		//				while (c != '\n') {
//		//					fscanf(sfptr, "%s:%[^\n]", singleWord.type[0], &singleWord.definition[0]);
//		//					c=fgetc(sfptr);
//		//				}
//		//			}
//		//			else {
//
//		//				singleWord.word[i] = c;
//		//				c = fgetc(sfptr);
//		//				i++;
//		//			}
//		//			
//		//		}
//		//		//printf("ndiauf");
//		//	}
//
//		//}
//		//printf("%s", singleWord.word);
//
///*int i = 0, index = -1;
//for (i = 0; i < totalWordCount; i++) {
//	if (strcmp(word, singleWord[i].word) == 0) {
//		index = i;
//	}
//}
//if (index != -1) {
//
//	for (i = 0; i < singleWord[index].defintionCount; i++) {
//
//		if (strcmp(singleWord[index].type[i], type) != 0) {
//
//			strcpy(singleWord[index].type[i], type);
//			strcpy(singleWord[index].definition[i], definition);
//		}
//	}
//}*/