/*
Name: Sahibpreet Singh
student id: 165338211
email: sahibpreet-singh1@myseneca.ca
date of submission: 16/02/2022
*/
#include <iostream>
#include "Mark.h"

namespace sdds{
	
	
	 Mark::Mark(int m ) {
		if (m>=0 && m<=100) {
			mark = m;
		}
		else {
			mark = -1;
		}
		
	}
	
	 Mark::operator int() const
	 {
		 int temp = 0;
		

		 if (bool(this)) temp = mark;
		 else { temp = 0; }
		 
		 return temp;
	 }
	 Mark::operator double()const {
		 double temp=-1; 
		 if (mark >= 80 && mark <= 100) {
			
			 temp = 4.0;
		 }
		 else if (mark < 80 && mark >= 70) {
			

			 temp = 3.0;
		 }
		 else if (mark < 70 && mark >= 60) {
			
			 temp = 2.0;
		 }
		 else if (mark < 60 && mark >= 50) {
			 
			 temp = 1.0;
		 }
		 else if (mark < 50 && mark >= 0) {
			
			 temp = 0.0;
		 }
		else {
			
			temp = 0.0;
		}
		return temp;
	}
	  Mark::operator char()const  {
		  char temp;
		  if (mark >= 80 && mark <= 100) {
			  temp = 'A';
			  
		  }
		  else if (mark < 80 && mark >= 70) {
			  temp = 'B';
			  
		  }
		  else if (mark < 70 && mark >= 60) {
			  temp = 'C';
			  
		  }
		  else if (mark < 60 && mark >= 50) {
			  temp = 'D';
			  
		  }
		  else if (mark < 50 && mark >= 0) {
			  temp = 'F';
			  
		  }

	  
		else {
			  temp = 'X';
		
		}
		return temp;
	}
	 Mark:: operator bool() const  {
		 bool isOk = false;
		 
		 if (mark >= 0 && mark <= 100) { isOk = true; }
		 return isOk;
	}

	  bool operator >=(const Mark& obj1, const Mark& obj2) {
		bool isOk = false;
		if (int(obj1) >= int(obj2))isOk = true;
		return isOk;
	}

	bool operator <=(const Mark& obj1, const Mark& obj2) {
		bool isOk = false;
		if (int(obj1) <= int(obj2))isOk = true;
		return isOk;
	}
	bool operator <(const Mark& obj1, const Mark& obj2) {
		bool isOk = false;
		if (int(obj1) < int(obj2))isOk = true;
		return isOk;

	}
	bool operator >(const Mark& obj1, const Mark& obj2) {
		bool isOk = false;
		if (int(obj1) > int(obj2))isOk = true;
		return isOk;

	}
	bool  operator ==(const Mark& obj1, const Mark& obj2) {
		bool isOk = false;
		if (int(obj1) == int(obj2))isOk = true;
		return isOk;

	}
	bool operator !=(const Mark& obj1, const Mark& obj2) {
		bool isOk = false;
		if (int(obj1) != int(obj2)) isOk = true;
		return isOk;
	 }
	Mark& Mark::operator++() {
		if(bool(*this))++mark;
		return *this;
	}

	Mark& Mark::operator--() {
		if (bool(*this))--mark;

		return *this;
	}
	Mark Mark::operator--(int ) {

		Mark temp = *this;
		if (bool(*this))mark--;
		return temp;
	}
	Mark Mark::operator++(int) {
		Mark temp = *this;
		if (bool(*this))mark++;
		return temp;
	}
	bool Mark::operator~() {
		bool isOk=false;
		if (bool(*this)) {
			if (mark >= 50) isOk = true;
		}
		return isOk;
	}
	Mark& Mark::operator=(int m)  {
		if (bool(this) ){
			this->set(m);

		}
		else {
			this->set(-1);
			
		}
		return *this;
	}
	Mark& Mark::operator+=(int m) {
		
		if (bool(this)==false) {
			mark = -1;
		}
		else {
			mark += m;
		}
		return *this;
	}
	Mark& Mark::operator-=(int m){
		if (bool(this) == false) {
			mark = -1;
		}
		else {
			mark -= m;
		}
		return *this;
		}
	int operator+=( int& val,const Mark& obj) {
		
		if (bool(obj)) {
			val += int(obj);
		}
		return val;
	}
	int operator-=( int& val,const Mark& obj) {
		
		if (bool(obj)) {
			val -= int(obj);
		}
		return val;
	}
	Mark&  Mark::operator<<(Mark& obj) {
		
		mark += int(obj);
		obj.set(0);
		return *this;

	}
	void Mark::set(int val) {
		mark = val;
	}
	Mark& Mark::operator>>(Mark& obj){
		
		int temp = int(obj);
		 temp+= mark;
		 obj.set(temp);
		mark = 0;
		return *this;
	}
	Mark Mark::operator+(int val)const {
		int tmp =mark + val;
		Mark temp=tmp ;
		if (!bool(temp)) {
			temp.set(-1);
		}
		return temp;

	}
	Mark Mark::operator+(const Mark& obj)const {
		int tmp = mark + int(obj);
		Mark temp = tmp;
		if (!bool(temp)) {
			temp.set(-1);
		}
		return temp;
	}
	int operator+( int val,const Mark&obj2){
		int tmp = val + int(obj2);
		Mark temp = tmp;
		if (!bool(temp)) {
			tmp = -1;
		}
		return tmp;
	}



}
