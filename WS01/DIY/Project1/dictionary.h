/*
Name: Sahibpreet Singh
email: sahibpreet-singh1@myseneca.ca
student id: 165338211
date of completion: 18 september 2022
*/
#ifndef SDDS_DICTIONARY_H
#define SDDS_DICTIONARY_H

using namespace std;
namespace sdds {
	const int MAXWORDS= 100;
	const int MAXDEFINTION = 8;
	const int MAXDEFINTIONCHARACTER = 1024;
	const int MAXTYPECHARACTER = 64;

	struct Word {
		char word[65];
		int defintionCount =0;
		char type[MAXDEFINTION][MAXTYPECHARACTER];
		char definition[MAXDEFINTION][MAXDEFINTIONCHARACTER];
	};
	
	
	int LoadDictionary(const char* filename);
	void SaveDictionary(const char* filename);
	void DisplayWord(const char* word);
	void AddWord(const char* word, const char* type, const char* definition);
	int UpdateDefinition(const char* word, const char* type, const char* definition);
	

};

#endif