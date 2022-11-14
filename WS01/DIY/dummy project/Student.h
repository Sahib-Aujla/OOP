#pragma once
#ifndef SDDS_STUDENT_H
#define SDDS_STUDENT_H

namespace sdds {
	//change to class
	//class Student
	struct Student {
		//add access modifier
	private:
		char* m_name{ nullptr }; //defaulting the value.
		int m_age{};
	public:
		void display() const; //The const qualifier identifies the member function as a query.  
		//A query does not change the state of its object.  
		//That is, this query cannot change the value of name and age. 

		//void display2() const; //member function to call from inside a member function

		void set(const char* nam, int ag); //modifier  both are same=const char* nam
		void setEmpty();
		bool isEmpty() const;
		void clearmemory();
	};
}

void display(); //global function
#endif