/*
Name: Sahibpreet singh
student id: 165338211
email: sahibpreet-singh1@myseneca.ca
date of completion: 24 october 2022
*/
#ifndef _SDDS_BASKET_H
#define _SDDS_BASKET_H
#include <iostream>
namespace sdds {

	struct Fruit
	{
		char m_name[30 + 1]; // the name of the fruit
		double m_qty;        // quantity in kilograms
	};

	class Basket {
		Fruit* fInfo{};
		int baskSize{};
		double price{};
		void setEmpty();

	public:
		Basket();
		Basket(const Fruit fruits[],const int size,const double price);
		Basket(Basket&);
		operator bool() const;
		void setPrice(double price);
		Basket& operator=(Basket&);
		Basket& operator+=(Fruit&);
		~Basket();
		friend std::ostream& operator<<(std::ostream& os, const Basket&);

	};



}



#endif