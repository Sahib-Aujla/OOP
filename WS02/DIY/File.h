/*
Name: Sahibpreet Singh
Student id: 165338211
email: sahibpreet-singh1@myseneca.ca
date of completion: 23 september 2022
*/
/***********************************************************************
// OOP244 Workshop 2 p2: tester program
//
// File  File.h
// Version 1.0
// Date  2022/09/17
// Author   Fardad Soleimanloo
// Description
// This file is incomplete and to be completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
#include "Population.h"
namespace sdds {
   // Opens a file and keeps the file pointer in the File.cpp (file scope)
   bool openFile(const char filename[]);
   // Closes the open file
   void closeFile();
   // Finds the records kept in the file to be used for the dynamic memory allocation 
   // of the records in the file
   int noOfRecords();
   bool read(int& value);
   bool read(char* cstr);
   bool read(Population& pop);
   int read(Population*& aptr);
}
#endif // !SDDS_FILE_H_
