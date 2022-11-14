/*
Name: Sahibpreet Singh
Student id: 165338211
email: sahibpreet-singh1@myseneca.ca
date of completion: 23 september 2022
*/
/***********************************************************************
// OOP244 Workshop 2 p2: tester program
//
// File  File.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include "File.h"
#include "Population.h"
using namespace std;
namespace sdds {
   FILE* fptr;
   // Opens a file and keeps the file pointer in the File.cpp (file scope)
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   // Finds and returns the number of records kept in the file 
   // to be used for the dynamic memory allocation of the records in the program
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   // Closes the open file
   void closeFile() {
      if (fptr) fclose(fptr);
   }
   bool read(int& value) {
       int check = 0;
       bool isOk = false;
       check = fscanf(fptr, "%d\n", &value);

       if (check > 0) {
           isOk = true;
       }
       return isOk;
   }
   bool read(char* cstr) {
       int check = 0;
       bool isOk = false;
       check = fscanf(fptr, "%[^,],", cstr);
       
       if (check > 0) {
           isOk = true;
       }
       return isOk;

   }
   bool read(Population& pop) {
       int tempVal = 0;
       char tempStr[4] = {};


       bool isOkk = read(tempStr);
       bool isOk = read(tempVal);

       if (isOk && isOkk) {
           int len = strlen(tempStr);
           pop.m_code = new char[len + 1];
           strcpy(pop.m_code, tempStr);
           pop.m_pop = new int;
           *pop.m_pop = tempVal;

       }
       
      
       return isOk && isOkk;
   }
   int read(Population*& aptr) {
       int fileCount = 0, count = 0;;
       fileCount = noOfRecords();
       
       if (fileCount) {
          
          aptr = new Population[fileCount];

           for (int i = 0; i < fileCount; i++) {
               bool isOk = read(aptr[i]);

               if (isOk) {
                   
                   count++;
               }
           }

       }
       if (fileCount != count) {
           fileCount = count;
           deallocateMemory();

           count = 0;
       }

       return count;
   }
}