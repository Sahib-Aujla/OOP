/*
Name: Ssahibpreet Singh
Student id: 165338211
email: sahibpreet-singh1@myseneca.ca
*/
#pragma once
#ifndef SDDS_APARTMENT_H_
#define SDDS_APARTMENT_H_
#include <iostream>

namespace sdds
{
   class Apartment
   {
      int m_number = -1;
      double m_balance = 0.0;

   public:
      Apartment(int number, double balance);
      std::ostream& display()const;
       operator bool() const;
       operator int() const;
       operator double() const;
       bool operator ~() const;
       Apartment& operator =(int);
       Apartment& operator =(Apartment&);
       Apartment& operator +=(float);
       Apartment& operator -=(float);
       Apartment& operator <<(Apartment&);
       Apartment& operator >>(Apartment& obj2);
   };

   double operator+(const Apartment&, const Apartment&);
   double operator+=(double&, const Apartment&);
}

#endif // SDDS_APARTMENT_H_