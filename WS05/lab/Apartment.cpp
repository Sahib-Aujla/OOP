/*
Name: Ssahibpreet Singh
Student id: 165338211
email: sahibpreet-singh1@myseneca.ca
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Apartment.h"

using namespace std;
namespace sdds
{
   Apartment::Apartment(int number, double balance)
   {

      if (number >= 1000 && number <= 9999
         && balance >= 0)
      {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Apartment::display() const
   {
      if (*this)
      {
         cout.width(4);
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else
      {
         cout << "Invld|  Apartment   ";
      }
      return cout;
   }
   Apartment::operator bool() const {
       bool isOk = false;
       if (m_number > 999 && m_number<10000 && m_balance >= 0) isOk = true;
       return isOk;
   }
   Apartment::operator int() const{
       return m_number;
   }
   Apartment::operator double() const {
       return m_balance;
   }
   bool Apartment::operator ~() const {
       return m_balance == 0;
   }
   Apartment& Apartment::operator =(int num) {
       if (num > 999 && num<10000) {
           m_number = num;
           
       }
       else {
           m_number = -1;
           m_balance = 0;
       }
       return *this;
   }
   Apartment& Apartment::operator =(Apartment& obj2) {
       int tempNum = m_number;
       m_number = obj2.m_number;
       obj2.m_number = tempNum;
       double tempBal = m_balance;
       m_balance = obj2.m_balance;
       obj2.m_balance = tempBal;
       return *this;
   }

   Apartment& Apartment::operator +=(float val) {
       if (val > 0 && m_number > 999 && m_number < 10000) {
           m_balance += val;
       }

       return *this;
   }
   Apartment& Apartment::operator -=(float val) {
       if (val > 0 && m_number > 999 && m_number < 10000 && m_balance>=val) {
           m_balance -= val;
       }
       return *this;
   }
   Apartment& Apartment::operator <<(Apartment& obj2) {
    
       if (m_number!=obj2.m_number&&m_balance >= 0 && m_number > 999 && m_number < 10000 && obj2.m_number > 999 && obj2.m_number < 10000) {
           m_balance += obj2.m_balance;
           obj2.m_balance = 0;
           
       }
       return *this;

   }
   Apartment& Apartment::operator >>(Apartment& obj2) {

       if (m_balance > 0 && m_number > 999 && m_number < 10000 && obj2.m_number > 999 && obj2.m_number < 10000) {
           obj2.m_balance += m_balance;
           m_balance = 0;
          // m_number = 0;
       }
       return *this;

   }
   double operator+(const Apartment& obj1, const Apartment& obj2) {
       
       double obj2bal = obj2;
       double obj1Bal = obj1;
       double sum = 0;
       if (obj2bal > 0 && obj1Bal>0) {
           sum = obj2bal + obj1Bal;
       }
       return sum;
   }
   double operator+=(double& val, const Apartment& obj1) {
       double obj1Bal = obj1;
       val += obj1Bal;
       return val;
   }


}