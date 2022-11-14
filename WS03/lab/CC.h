/*
Name: Sahibpreet singh
student id: 165338211
email: sahibpreet-singh1@myseneca.ca
DOS: 29 sept 2022
*/

#ifndef SDDS_CC_H
#define SDDS_CC_H

namespace sdds {
	class CC {
		char* holderName;
		short cvv, expMonth, expYear;
		unsigned long long cardNum;

		bool validate(const char* name,
			unsigned long long cardNo,
			short cvv,
			short expMon,
			short expYear)const;
		void prnNumber()const;
	public:
		void set();
		void cleanUp();
		bool isEmpty() const;
		void set(const char* cc_name,
			unsigned long long cc_no,
			short cvv,
			short expMon,
			short expYear);
		bool read();
		void display(int row =0) const ;
	};
}

#endif // !///SDDS_CC_H
