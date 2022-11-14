/*
Name: Sahibpreet Singh
student id: 165338211
email: sahibpreet-singh1@myseneca.ca
date: 14/09/2022
*/
#ifndef SDDS_SHOPPINGLIST_H
#define SDDS_SHOPPINGLIST_H


namespace sdds {
	const int MAX_NO_OF_RECS = 15;



	bool loadList();
	void displayList();
	void removeBoughtItems();
	void removeItem(int index);
	bool saveList();
	void clearList();
	void toggleBought();
	void addItemToList();
	void removeItemfromList();
	bool listIsEmpty();
}
#endif