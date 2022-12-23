/*
Name: Sahibpreet Singh
Student id: 165338211
email: sahibpreet-singh1@myseneca.ca
*/

/* Citation and Sources...
Final Project Milestone 5
Module: Menu
Filename: Menu.cpp
-----------------------------------------------------------
I have done all the coding by myself and used the code
provided in the starter files.
-----------------------------------------------------------*/
#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>
namespace sdds {
	const int MAX_NO_OF_ITEMS = 10;
	class Menu;
	class MenuItem {
		char menuItem[51];
		int notEmpty;
		friend Menu;
		MenuItem();
		MenuItem(const char* item);
		std::ostream& displayItem(std::ostream& os = std::cout) const;
		MenuItem& setItem(const char* item);
		MenuItem(const MenuItem&) = delete;
		MenuItem& operator=(const MenuItem&) = delete;
	};
	class Menu {
		char menuTitle[51];
		MenuItem items[MAX_NO_OF_ITEMS];
		int identation;
		int empty = 0;
	public:
		void clear();

		Menu(const char* title, const int ident = 0);
		Menu(const Menu&) = delete;
		Menu& operator=(const Menu&) = delete;
		operator bool() const;
		bool isEmpty() const;
		std::ostream& display(std::ostream& os = std::cout)const;
		int emptyIndex();
		Menu& operator=(const char* title);
		void add(const char* item);

		Menu& operator<<(const char*);
		int run() const;
		operator int() const;
		int count() const;
	};





}
#endif