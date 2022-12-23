/*
Name: Sahibpreet Singh
student id: 165338211
email: sahibpreet-singh1@myseneca.ca
date: 23 November 2022
*/

#ifndef SDDS_TEXT_H
#define SDDS_TEXT_H
#include <iostream>
namespace sdds {
	class Text {
		char* m_content;
	protected:
		const char& operator[](int index)const;
		
	public:
		Text();
		Text(const Text&);
		Text& operator=(const Text&);
		virtual ~Text();
		unsigned getFileLength(std::istream& is);
		virtual std::istream& read( std::istream&);
		virtual std::ostream& write(std::ostream&)const;

	};
	std::istream& operator>>(std::istream& in, Text&);
	std::ostream& operator<<(std::ostream& os,const Text&);

};



#endif