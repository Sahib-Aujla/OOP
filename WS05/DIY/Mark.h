/*
Name: Sahibpreet Singh
student id: 165338211
email: sahibpreet-singh1@myseneca.ca
date of submission: 16/02/2022
*/
#ifndef SDDS_MARK_H
#define SDDS_MARK_H

namespace sdds {
	class Mark {
		int mark;
	public:
		void set(int);
		Mark(int m = 0);
		
		operator int() const;
		operator double() const;
		operator char() const;
		operator bool() const;
		Mark& operator++();
		Mark& operator--();
		Mark operator--(int);
		Mark operator++(int);
		bool operator~();
		Mark& operator=(int);
		Mark& operator+=(int);
		Mark& operator-=(int);
		

		 Mark& operator<<(Mark&);
		 Mark& operator>>(Mark&);

		 Mark operator+(int)const;
		 Mark operator+(const Mark&)const;
		 

	};
	bool operator >=(const Mark& obj1, const Mark& obj2);
	bool operator <=(const Mark& obj1, const Mark& obj2);
	bool operator <(const Mark& obj1, const Mark& obj2);
	bool operator >(const Mark& obj1, const Mark& obj2);
	bool operator ==(const Mark& obj1, const Mark& obj2);
	bool operator !=(const Mark& obj1, const Mark& obj2);

	int operator+=( int&,const Mark&);
	int operator-=( int& val,const Mark& obj);
	int operator+( int,const Mark&);
}

#endif