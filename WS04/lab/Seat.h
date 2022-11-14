/*
Name: Sahibpreet Singh
student id: 165338211
email: sahibpreet-singh1@myseneca.ca
Date of completion: 4 sept 2022
*/
#ifndef SDDS_SEAT_H_
#define SDDS_SEAT_H_
#include <iostream>
namespace sdds {
   class Seat {
	   char* passengerName;
	   int row_no=0;
	   char seat_letter='\0';

	   bool validate(int row, char letter)const;
	   Seat& alAndCp(const char* str);
	   
	
   public:
	   //constructors
	   Seat();
	   Seat(const char* passengerName);
	   Seat(const char* passengerName, int row, char letter);

	  
	   Seat& reset();

	   bool isEmpty() const;
	   bool assigned() const;
	   Seat& set(int row, char letter);
	   int row()const;
	   char letter()const;
	   const char* passenger()const;


	   //input/output
	   std::ostream& display(std::ostream& coutRef = std::cout)const;
	   std::istream& read(std::istream& cinRef = std::cin);

	   
	   ~Seat();

   };
}
#endif // !SDDS_SEAT_H_


