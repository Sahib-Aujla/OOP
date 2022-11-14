/*
Name: Sahibpreet singh
student id: 165338211
email: sahibpreet-singh1@myseneca.ca
DOS: 29 sept 2022
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "CC.h"

using namespace std;

namespace sdds {
	bool CC::validate(const char* name,unsigned long long cardNo,
		short cvv,
		short expMon,
		short expYear)const {
		bool isOk = true;
		
		if (name == nullptr || strlen(name)<=2) isOk = false;
		
		if (cardNo <= 4000000000000000 || cardNo >=4099999999999999) isOk = false;

		if (cvv <= 100 || cvv >=999) isOk = false;

		if (expMon < 1 || expMon >12) isOk = false;


		if (expYear < 22 || expYear >32) isOk = false;

		return isOk;

	}
	void CC::prnNumber()const {
		unsigned long long temp = cardNum;
		unsigned long long nTemp = temp / 1000000000000;

		cout.setf(ios::right);
		cout.width(4);
		cout.fill('0');
		cout << nTemp << " ";
		 temp = temp % 1000000000000;
		 nTemp = temp / 100000000;
		 cout.width(4);
		 cout.fill('0');
		 cout << nTemp << " ";
		 temp = temp % 100000000;
		 nTemp = temp / 10000;
		 cout.width(4);
		 cout.fill('0');
		 cout << nTemp << " ";
		 temp = temp % 10000;
		 cout.width(4);
		 cout.fill('0');
		 cout << temp ;

		cout.fill(' ');
		cout.unsetf(ios::right);
		
	}

	void CC::set() {
		holderName = nullptr;
		cvv={};
		expMonth = {};
		expYear = {};
		cardNum = {};
	}

	void CC::cleanUp() {
		delete[] holderName;
		set();
	}
	bool CC::isEmpty() const {
		bool isOK = false;
		if (holderName == nullptr) isOK = true;

		return isOK;
	}
	void CC::set(const char* cc_name,
		unsigned long long cc_no,
		short cvv,
		short expMon,
		short expYear) {
		cleanUp();
		bool isOk=validate(cc_name, cc_no, cvv, expMon, expYear);
		
		if (isOk) {
			size_t len = strlen(cc_name);
			holderName = new char[len + 1];
			strcpy(holderName, cc_name);
			this->cvv = cvv;
			expMonth = expMon;
			this->expYear = expYear;
			cardNum = cc_no;
		}
	}

	bool CC::read() {
		char hName[71]{};
		short cvv{}, expMon{}, expYear{};
		unsigned long long cc_no{};
		bool isOk = false;
		cleanUp();
		cout << "Card holder name: ";
		cin.getline(hName, 71, '\n');
		if(!cin.fail()) cout << "Credit card number: ";
		cin >> cc_no;
		if (!cin.fail()) cout << "Card Verification Value (CVV): ";
		cin >> cvv;
		if (!cin.fail()) cout << "Expiry month and year (MM/YY): ";
		cin >> expMon;
		cin.ignore();
		cin >> expYear;

		if (!cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			set(hName, cc_no, cvv, expMon, expYear);
			if (holderName != nullptr) {
				isOk = true;
			}
		}
		else {
			cin.clear();
			cin.ignore(10000, '\n');
		}
		

		return isOk;
	}

	void CC::display(int row ) const {
		if (isEmpty()==true) {
			cout << "Invalid Credit Card Record"<< endl;
		}
		else {
			if (row <= 0) {
				cout << "Name: " << holderName << endl;
				cout << "Creditcard No: ";
					prnNumber() ;
				cout <<endl<< "Card Verification Value: " << cvv << endl;
				cout << "Expiry Date: " << expMonth << "/" << expYear << endl;

			}
			else {
				cout << "| ";
				cout.width(3);
				cout << row << " | ";
				
				cout.setf(ios::left);
				
				if (strlen(holderName) > 30) cout.write(holderName, 30);
				else { 
					cout.width(30);
					cout << holderName; 
				}
				
				cout<<" | ";
				cout.unsetf(ios::left);
				cout.setf(ios::right);
			
				prnNumber();
				
				cout << " | " << cvv << " | ";
				cout.width(2);
				cout << expMonth << "/";
				cout.width(0);
				cout << expYear << " |"<<endl;



			}
		}

	}

}