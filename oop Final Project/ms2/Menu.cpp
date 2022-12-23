/*
Name: Sahibpreet Singh
Student id: 165338211
email: sahibpreet-singh1@myseneca.ca
*/

/* Citation and Sources...
Final Project Milestone 2
Module: Menu
Filename: Menu.cpp
-----------------------------------------------------------
I have done all the coding by myself and used the code
provided in the starter files.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Menu.h"
#include "Utils.h"

using namespace std;
namespace sdds {
	Menu::Menu(const char* title, const int ident) {
		identation = ident;

		if (title != nullptr) {
			strncpy(menuTitle, title, 50);
			empty = 1;

		}
		else {
			clear();
			identation = 0;
		}

	}

	Menu::operator bool() const {
		return (!isEmpty());
	}

	bool Menu::isEmpty() const {
		return empty == 0;
	}
	ostream& Menu::display(ostream& os) const {
		if (isEmpty()) {
			os << "Invalid Menu!" << endl;
		}
		else if (items[0].notEmpty == 0) {
			os << menuTitle << endl;
			os << "No Items to display!" << endl;
		}
		else {

			int c = count();
			for (int j = 0; j < identation; j++) {
				os << "    ";
			}
			os << menuTitle << endl;


			for (int i = 0; i < c; i++) {
				for (int j = 0; j < identation; j++) {
					os << "    ";
				}
				os << i + 1 << "- ";
				os << items[i].menuItem;
				os << endl;
			}
			for (int j = 0; j < identation; j++) {
				os << "    ";
			}
			os << "> ";
		}
		return os;
	}
	Menu& Menu::operator=(const char* title) {
		if (title != nullptr) {
			strncpy(menuTitle, title, 50);
			empty = 1;
			strcpy(items[0].menuItem, "\0");
			items[0].notEmpty = 0;
		}
		else {
			clear();
		}
		return *this;
	}
	MenuItem::MenuItem() {
		strcpy(menuItem, "\0");

		notEmpty = 0;
	}
	void Menu::clear() {
		items[0].notEmpty = 0;
		empty = 0;
		strcpy(menuTitle, "\0");

	}

	int Menu::emptyIndex() {
		int index = -1, i = 0;
		for (i = 0; i < MAX_NO_OF_ITEMS && index == -1; i++) {

			if (items[i].notEmpty == 0) {

				index = i;

			}
		}

		return index;
	}
	void Menu::add(const char* item) {


		if (menuTitle == nullptr || item == nullptr) {

			clear();


		}
		else {
			int index = emptyIndex();

			if (index != -1) {
				items[index].setItem(item);
			}
		}
	}
	Menu& Menu::operator<<(const char* item) {
		add(item);
		return *this;
	}


	int Menu::run() const {
		int selection = 0, flag = 0;
		display();
		if (!isEmpty()) {

			if (items[0].notEmpty) {
				while (flag == 0) {
					selection = validInt();
					int c = count();
					if (selection >= 1 && selection <= c) {
						flag = 1;
						cin.clear();
						cin.ignore(1000, '\n');
					}
					else {
						cout << "Invalid selection, try again: ";
					}
				}
			}

		}
		return selection;
	}

	int Menu::count() const {
		int c = -1, i = 0;
		for (i = 0; i < MAX_NO_OF_ITEMS && c == -1; i++) {
			if (items[i].notEmpty == 0) {
				c = i;
			}
		}
		return c;
	}

	Menu::operator int() const {
		return run();
	}

	MenuItem::MenuItem(const char* item) {
		if (item != nullptr) {
			strncpy(menuItem, item, 50);
			notEmpty = 1;
		}
		else {
			strcpy(menuItem, "\0");
			notEmpty = 0;
		}
	}

	ostream& MenuItem::displayItem(ostream& os) const {

		if (notEmpty != 0) {
			os << this->menuItem << endl;
		}
		return os;
	}


	MenuItem& MenuItem::setItem(const char* item) {

		strncpy(menuItem, item, 50);
		notEmpty = 1;

		return*this;
	}


}