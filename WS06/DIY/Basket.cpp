/*
Name: Sahibpreet singh
student id: 165338211
email: sahibpreet-singh1@myseneca.ca
date of completion: 24 october 2022
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstring>
#include "Basket.h"

namespace sdds {
	Basket::Basket() {
		setEmpty();
	}

	Basket::Basket(const Fruit fruits[], int size, double price) {
		if (fruits != nullptr && size > 0) {
			int i = 0;
			baskSize = size;
			fInfo = new Fruit[baskSize];
			for (i = 0; i < size; i++) {
				strcpy(fInfo[i].m_name, fruits[i].m_name);
				fInfo[i].m_qty = fruits[i].m_qty;
			}
			this->price = price;

		}

	}

	Basket::operator bool() const {
		return fInfo != nullptr;
	}
	std::ostream& operator<<(std::ostream& os, const Basket& obj) {
		if (obj.fInfo != nullptr) {
			int i = 0;
			os << "Basket Content:" << std::endl;
			os.setf(std::ios::right);
			os.width(10);
			for ( i = 0; i < obj.baskSize; i++) {
				os.setf(std::ios::right);
				os.width(10);
				os << obj.fInfo[i].m_name << ": ";
				os.unsetf(std::ios::right);
				os << obj.fInfo[i].m_qty << "kg" << std::endl;

			}
			os.setf(std::ios::fixed);
			os.precision(2);
			os << "Price: " << obj.price << std::endl;
		}
		else {
			os << "The basket is empty!" << std::endl;
		}
		return os;
	}
	Basket::Basket(Basket& obj) {
		*this = obj;
	}
	Basket& Basket::operator=(Basket& obj) {

		if (obj) {
			int i = 0;
			delete[] fInfo;
			setEmpty();
			fInfo = new Fruit[obj.baskSize];
			baskSize = obj.baskSize;
			price = obj.price;
			for ( i = 0; i < baskSize; i++) {
				strcpy(fInfo[i].m_name,obj.fInfo[i].m_name);
				fInfo[i].m_qty = obj.fInfo[i].m_qty;
			}
			delete[] obj.fInfo;
			obj.setEmpty();
		}
		return *this;
	}
	void Basket::setPrice(double price) {
		this->price = price;
	}
	Basket& Basket::operator+=(Fruit& obj) {
		int i = 0;
		Fruit* temp = new Fruit[baskSize+1];
		for (i = 0; i < baskSize; i++) {
			strcpy(temp[i].m_name, fInfo[i].m_name);
			temp[i].m_qty = fInfo[i].m_qty;
		}
		strcpy(temp[i].m_name, obj.m_name);

		temp[baskSize].m_qty = obj.m_qty;
		baskSize++;
		delete[] fInfo;
		fInfo = nullptr;
		fInfo = new Fruit[baskSize];
		for (i = 0; i < baskSize; i++) {
			strcpy( fInfo[i].m_name, temp[i].m_name) ;
			 fInfo[i].m_qty=temp[i].m_qty;
		}
		delete[] temp;
		return *this;
	}
	Basket::~Basket() {
		delete[] fInfo;
		setEmpty();
	}
	void Basket::setEmpty() {
		fInfo = nullptr;
		baskSize = 0;
		price = 0;
	}

}