#pragma once
//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//#include <cstdio>
//#include "dictionary.h"
//using namespace std;
//
//namespace sdds {
//	Word word1[100];
//	Dictionary dictionary;
//	char c;
	//int loaddictionary(const char* filename) {
	//	file* sfptr = fopen(filename, "r");
	//	int k = sfptr == nullptr;
	//	int ok = 0;
	//	if (!k) {
	//		int i = 0;
	//		char c;
	//		int j;
	//		do {
	//			//cout << "do while " << endl;
	//			ok = fscanf(sfptr, "%s", word1[i].word);
	//			fgetc(sfptr);
	//			if (ok > 0) {
	//				//cout << "if " << endl;

	//				c = fgetc(sfptr);
	//				j = 0;
	//				while (c == '\t') {
	//					//	cout << " while " << endl;

	//					fscanf(sfptr, "%[^:]: %[^\n]", word1[i].type[j], word1[i].definition[j]);
	//					//fscanf(sfptr, ":%[^\n]", word1[i].definition[j]);
	//					//cout << "type  " << word1[i].type[j] << ":" << word1[i].definition[j] << "..." << endl;
	//					word1[i].defin++;
	//					fgetc(sfptr);
	//					j++;
	//					c = fgetc(sfptr);

	//				}
	//			}
	//			//cout << word1[i].defin << " num";

	//			//cout << word1[i].word << " word " << endl;
	//			strcpy(dictionary.words[i], word1[i].word);
	//			dictionary.count++;

	//			//cout << "dictionary  " << dictionary.words[i]<<"count= "<<dictionary.count << endl;
	//			i++;
	//		} while (!feof(sfptr));
	//		fclose(sfptr);
	//	}
		//cout << "type  " << word1[1].type[4] << ":" << word1[1].definition[4] << "..." << endl;
		//strcpy(word1[1].definition[4], "\0");
		return k;
	}
//
//	void SaveDictionary(const char* filename) {
//		FILE* sfptr = fopen(filename, "w");
//		//int k = sfptr == nullptr;
//		for (int i = 0; i < dictionary.count; i++) {
//			fprintf(sfptr, "%s", word1[i].word);
//			fputc('\n', sfptr);
//			//cout <<"saved word "<< word1[i].word << endl;
//			for (int j = 0; j < word1[i].defin; j++) {
//				fprintf(sfptr, "\t%s: %s\n", word1[i].type[j], word1[i].definition[j]);
//				//cout << "saved def and type " << word1[i].type[j]<< word1[i].definition[j] << endl;
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
//		for (i = 0; i < dictionary.count; i++) {
//			if (strcmp(word, dictionary.words[i]) == 0) {
//				index = i;
//			}
//		}
//		if (index != -1) {
//			cout << "FOUND: [" << dictionary.words[index] << "] has [" << word1[index].defin << "] defintiions:" << endl;
//			for (i = 0; i < word1[index].defin; i++) {
//				cout << i + 1 << ". {" << word1[index].type[i] << "} " << word1[index].definition[i] << endl;
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
//		for (i = 0; i < dictionary.count; i++) {
//			if (strcmp(word, word1[i].word) == 0) {
//				//cout << word << word1[i].word << endl;
//				index = i;
//			}
//		}
//		if (index == -1) {
//
//			emptyIndexWord = findEmptyIndex(1, 0);
//
//			index = emptyIndexWord;
//			strcpy(word1[index].word, word);
//			strcpy(dictionary.words[index], word);
//			dictionary.count++;
//		}
//		emptyIndexWord = findEmptyIndex(0, index);
//
//		//cout << "empty index " << emptyIndexWord << endl;
//		strcpy(word1[index].type[emptyIndexWord], type);
//		strcpy(word1[index].definition[emptyIndexWord], definition);
//		//cout << index<<"  " << word1[index].type[emptyIndexWord] << endl;
//		//cout << index<<"  def :" << word1[index].definition[emptyIndexWord] << endl;
//
//
//		word1[index].defin++;
//
//
//
//		return;
//	}
//	int UpdateDefinition(const char* word, const char* type, const char* definition) {
//		int i = 0, index = -1;
//		for (i = 0; i < dictionary.count; i++) {
//			if (strcmp(word, word1[i].word) == 0) {
//				//cout << word << " " << word1[i].word<<endl;
//				index = i;
//			}
//		}
//		if (index != -1) {
//			//cout << "index"<<index<<" " << word1[index].word << endl;
//
//			for (i = 0; i < word1[index].defin; i++) {
//				//cout<<"for "<<word1[index].type[i] << endl;
//				if (strcmp(word1[index].type[i], type) != 0) {
//					//cout <<"if"<< word1[index].type[i] << endl;
//					//cout << word1[index].definition[i] <<"defintion  " << definition << endl;
//					strcpy(word1[index].type[i], type);
//					strcpy(word1[index].definition[i], definition);
//				}
//			}
//		}
//
//		//if(strcmp())
//		return 0;
//	}
//
//
//	int findEmptyIndex(int flagType, int wordIndex) {
//		int flag = 0, i = 0, index = -1;
//		if (flagType == 1) {
//			while (flag == 0 && i < 100) {
//				if (strlen(word1[i].word) == 0) {
//					flag = 1;
//					index = i;
//				}
//				i++;
//			}
//		}
//		else {
//			while (flag == 0 && i < 8) {
//				if (strlen(word1[wordIndex].definition[i]) == 0) {
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
//		for (int i = 0; i < dictionary.count; i++) {
//			strcpy(dictionary.words[i], "\0");
//			/*for(int j=0;j<word1[i].defin;)*/
//			word1[i].defin = 0;
//		}
//	}
//
//};
//
//
//
//
////
////int i = 0;
////while (!feof(sfptr)) {
////	int j = 0;
////	fscanf(sfptr, "%[^\n]", word1[i].word);
////	//printf("%s khdk", word1[i].word);
////	cout << "hahah  " << word1[i].word << endl;
////	//fscanf(sfptr, "%[\t]", c);
////	/*c = fgetc(sfptr);
////	cout << c << "tab" << endl;*/
////	c = fgetc(sfptr);
////	cout << c << "tab" << endl;
////	if (c == '\t') {
////		fscanf(sfptr, "%[^:]:%[^\n]", word1[i].type[0], word1[i].definition[0]);
////		cout << word1[i].type[0] << "  lol   " << word1[i].definition[0] << endl;
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
//		//					fscanf(sfptr, "%s:%[^\n]", word1.type[0], &word1.definition[0]);
//		//					c=fgetc(sfptr);
//		//				}
//		//			}
//		//			else {
//
//		//				word1.word[i] = c;
//		//				c = fgetc(sfptr);
//		//				i++;
//		//			}
//		//			
//		//		}
//		//		//printf("ndiauf");
//		//	}
//
//		//}
//		//printf("%s", word1.word);
