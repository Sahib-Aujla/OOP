#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Student {
	string name;
	int age;

public:
	Student();
	Student(string h,int);
	void display() {
		cout << "name is " << name << " and age is " << age << endl;
	}
	~Student() {
		cout << "name " << name<<endl;
		name = nullptr;
		age = 0;
	}
};
Student::Student() {
	name = nullptr;
	age = 0;

}
Student::Student(string h,int a) {
	name = h;
	
	age = a;

}

int main() {
	Student s1("haha", 33), s2("lol", 443);

	s1.display();
	s2.display();
	return 0;
}