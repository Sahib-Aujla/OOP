/*
Name: Sahibpreet Singh
Student id: 165338211
email: sahibpreet-singh1@myseneca.ca
Date of completion: 07 octtober 2022
*/
#ifndef TOURBUS_H
#define TOURBUS_H
#include "TourTicket.h"
namespace sdds {
	class TourBus {
		TourTicket* tourTick=nullptr;
		int totalPassengers=0;
		int boardedPass=0;

	public:
		TourBus();
		TourBus(int);
		void set();
		bool validTour()const;
		void startTheTour()const;
		TourBus& board();
		void reset();
		~TourBus();
	};
}

#endif // !TourBus.h
