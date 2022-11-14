/*
Name: Sahibpreet Singh
student id: 165338211
email: sahibpreet-singh1@myseneca.ca
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include<iostream>
#include "Numbers.h"
using namespace std;
namespace sdds {


   Numbers::Numbers() { 
      setEmpty();
      m_isOriginal = false;
   } 

   Numbers::Numbers(const char* filename) { 

      setEmpty();

      m_isOriginal = true;

      setFilename(filename);

      m_numCount = numberCount();

      if (m_numCount == 0 || !load()) {
         deallocate();
         setEmpty();
         m_isOriginal = false; 
      }
   }

   Numbers::~Numbers() {
      save();
      deallocate();
   }

   bool Numbers::isEmpty() const { 
      return m_numbers == nullptr;
   }

   void Numbers::setEmpty() { 
      m_numbers = nullptr;
      m_filename = nullptr;
      m_numCount = 0;
   }

   void Numbers::deallocate() {
      delete[] m_filename;
      delete[] m_numbers;
   }

   void Numbers::setFilename(const char* filename) { 
      delete[] m_filename;
      m_filename = new char[strlen(filename) + 1];
      strcpy(m_filename, filename);
   }

   
  

   double Numbers::average() const {
      double aver = 0.0;
      if (!isEmpty()) {
         for (int i = 0; i < m_numCount; i++)
            aver += m_numbers[i];
         aver = aver / m_numCount;
      }
      return aver;
   }

   double Numbers::min() const {
      double minVal = 0.0;
      if (!isEmpty()) {
         minVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (minVal > m_numbers[i]) minVal = m_numbers[i];
      }
      return minVal;
   }
   double Numbers::max() const {
      double maxVal = 0.0;
      int i = 0;
      if(!isEmpty()) {
         maxVal = m_numbers[0];
         for( i = 1; i < m_numCount; i++)
            if(maxVal < m_numbers[i]) maxVal = m_numbers[i];
      }
      return maxVal;
   }
  
   Numbers::Numbers(const Numbers& obj) {
       *this = obj;
  }


   Numbers& Numbers::operator=(const Numbers& obj) {
      
       if (this != &obj) {
           deallocate();
           setEmpty();
           m_isOriginal = false;
           m_numbers = new double[obj.m_numCount+1];
           m_numCount = obj.m_numCount;
           m_filename = new char[strlen(obj.m_filename) + 1];
           strcpy(m_filename, obj.m_filename);
           int i = 0;
           for (i = 0; i < m_numCount; i++) {
               m_numbers[i] = obj.m_numbers[i];
           }
       }
       return *this;
   }

   bool Numbers::load() {
       int i = 0;
       int count = numberCount();
       
       if (count > 0) {
          std:: ifstream fin;
           fin.open(m_filename);
           m_numbers = new double[count+1];
           int flag = 0;
           while (flag==0) {
               double temp;
               fin >> temp;

               m_numbers[i] = temp;
               fin.ignore();
               
               if (fin.fail() == true) {
                  
                   flag = 1;
               }
               else {
                   i++;
               }
           }
           fin.clear();
           fin.ignore(1111, '\n');
           fin.close();
       }
      
      
       return count==i;
   }

   int Numbers::numberCount() const{
       int count = 0;
       std::ifstream fin;
       fin.open(m_filename);
      

       while (fin.fail()==false) {
           if (fin.get() == '\n') {
               count++;
           }
          
       }
      
       fin.close();
       return count;
   }
   void Numbers::save() {
     
     
       if (!isEmpty() && m_numCount > 0 &&m_isOriginal==true) {
           
           std::ofstream fout;
           fout.open(m_filename);
           for (int i = 0; i < m_numCount; i++) {
               fout.setf(std::ios::fixed);
               fout.precision(2);
               fout << m_numbers[i] << std::endl;
           }
           fout.unsetf(std::ios::fixed);
           fout.precision(6);
      
       }
   }

   Numbers& Numbers::sort(bool ascending) {
       double temp;
       if (ascending) {
           int i, j;
           for (i = 0; i < m_numCount - 1; i++) {

               for (j = 0; j < m_numCount - i - 1; j++) {
                   if (m_numbers[j] > m_numbers[j + 1]) {
                       temp = m_numbers[j];
                       m_numbers[j] = m_numbers[j+1];
                       m_numbers[j + 1] = temp;

                   }
               }
           }
       }
       else {
           int i, j;
           for (i = 0; i < m_numCount - 1; i++) {

               for (j = 0; j < m_numCount - i - 1; j++) {
                   if (m_numbers[j] < m_numbers[j + 1]) {
                       temp = m_numbers[j];
                       m_numbers[j] = m_numbers[j + 1];
                       m_numbers[j + 1] = temp;

                   }
               }
           }
       }
       return *this;
   }
   Numbers Numbers::operator-()const {
       Numbers temp = *this;
       temp.sort(0);
       return temp;
   }
   Numbers Numbers::operator+()const {
       Numbers temp = *this;
       temp.sort(1);
       return temp;
   }

   Numbers& Numbers::operator+=(double j) {
  
       if (!isEmpty() && m_numCount>0) {
           int i = 0;
           double* temp = new double[m_numCount + 2];
           for (i = 0; i < m_numCount; i++) {
               temp[i] = m_numbers[i];

           }
           temp[i] = j;
           delete[] m_numbers;
           m_numCount++;
           m_numbers = new double[m_numCount+1];
           for (i = 0; i < m_numCount; i++) {
                m_numbers[i]=temp[i] ;

           }
           delete[] temp;
       }
     

       return *this;
   }
   std::ostream& operator<<(std::ostream& os, const Numbers& N) {
       
       return  N.display(os);
      
   }
   std::istream& operator>>(std::istream& istr, Numbers& N) {
       double temp;
       istr >> temp;
       if(!istr.fail()){
         
           N += temp;
       }
       return istr;
   }
   ostream& Numbers::display(ostream& ostr)const {
       if (!isEmpty()) {
           int i = 0;
           ostr << "=========================" << endl;
           if (m_isOriginal == false) { ostr << "*** COPY ***"<<endl; }
           else { ostr << m_filename << endl; }
           for (i = 0; i < m_numCount; i++) {
               ostr.setf(std::ios::fixed);
               ostr.precision(2);
               ostr << m_numbers[i] ;
               if (i != (m_numCount - 1)) { ostr << ", "; }
           }
           ostr <<endl<<"-------------------------"<< endl;
           ostr << "Total of "<<m_numCount<<" number(s)" << endl;
           ostr << "Largest number:  " << max() << endl;
           ostr << "Smallest number: " << min()<<endl;
           ostr << "Average:         " << average()<<endl;
           ostr << "=========================" ;

           ostr.unsetf(std::ios::fixed);

         

       }
       else {
           ostr << "Empty list" ;
       }
       return ostr;
   }


   
}
