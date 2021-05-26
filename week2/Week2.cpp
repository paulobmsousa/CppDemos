// Week1.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <string.h>
#include "Week2.h"

using namespace std;

// CLASSES ..........................................................................................................

/*
* MyFirstClass: Example using Person definitions
*/

#define DEBUG false

namespace CST8219 {

	class MyFirstClass {
	protected:
		int age;
		char* firstName, * lastName;
	public:
		MyFirstClass() {
			#if DEBUG
				cout << "Creating[1] "
					<< typeid(this).name() << endl;
			#endif
			age = 0;
			firstName = lastName = NULL;
		}

		MyFirstClass(int a) {
			age = a; 
			// Need to assign defaults 
			firstName = lastName = NULL;
		}

		MyFirstClass(int a, char* f, char* l) {
			#if DEBUG
				cout << "Creating[2] "
					<< typeid(this).name() << endl;
			#endif
			age = a;
			firstName = f;
			lastName = l;
		}
		int getAge() {
			return age;
		}
		char* getFirstName() {
			if (firstName != NULL)
				return firstName;
			return "[Null]";
		}
		char* getLastName() {
			if (lastName != NULL)
				return lastName;
			return "[Null]";
		}
		void printClass() {
			cout 
				<< "FirstName: " << getFirstName()
				<< " - Lastname: " << getLastName()
				<< " - Age: " << getAge()
				<< endl;
		}
		void setFirstName(char* f) {
			firstName = f;
		}
		void setLastName(char* l) {
			lastName = l;
		}
		void setAge(int a) {
			age = a;
		}
		#if DEBUG
			~MyFirstClass() {
				cout << "Deleting "
					<< typeid(this).name()
					<< endl;
			}
		#endif
	protected:
		;
	};

	/*
	* MySecondClass: Another class
	*/

	class MySecondClass : public MyFirstClass {
	private:
		char fullName[NAMESIZE] = {};
	public:
		char* getFullName() {
			strcpy(fullName, getLastName());
			strcat(fullName, ", ");
			strcat(fullName, getFirstName());
			return fullName;
		}
		void printFullName() {
			cout
				<< "Fullname: " << getFullName()
				<< endl;
		}
		#if DEBUG
			~MySecondClass() {
				cout << "Deleting " 
					<< typeid(this).name()
					<< endl;
			}
		#endif
	protected:
		;
	};

	/*
	* Class ExtraClass: Another class
	*/

	class ExtraClass {
	private:
		string name;
		int x, y;
	public:
		ExtraClass(char* str) : name(str), x(0), y(0) {
		#if DEBUG
			cout << "Creating "
				<< typeid(this).name() << endl;
		#endif
			// Similar to: name=str, x=0, y=0
		}
		void printData() {
			cout
				<< "Name: " << name
				<< ", x: " << x
				<< ", y: " << y << endl;
		}
	#if DEBUG
		~ExtraClass() {
			cout << "Deleting "
				<< typeid(this).name()
				<< endl;
		}
	#endif
	};
}//nameSpace end

// METHODS  ..........................................................................................................

int week2() {
#pragma message("Week 2 Lab ..................................")
	cout << "Week 2 Lab .................................." << endl;
	testClasses();
	//testInput();
	return 0;
}

void testInput(){
	int num;
	cout << "Type a number: ";
	if (cin >> num)
		cout << "You have entered a number " << num << endl;
	else
		cout << "ERROR, Please enter a number!" << endl;
}

void testClasses() {
	using namespace CST8219;

	// Using MyFirstClass
	MyFirstClass mfc1 = MyFirstClass();
	mfc1.printClass();

	MyFirstClass mfc2 = MyFirstClass(49, "Paulo", "Sousa");
	mfc2.printClass();

	MyFirstClass mfc3 = MyFirstClass(10, "F", "L");
	mfc3.printClass();

	MyFirstClass mfc4 = MyFirstClass(99); 
	mfc4.printClass();

	// Using MySecondClass
	MySecondClass msc1 = MySecondClass();
	msc1.setAge(mfc1.getAge());
	msc1.setFirstName(mfc2.getFirstName());
	msc1.setLastName(mfc3.getLastName());
	msc1.printFullName();

	// Using ExtraClass
	ExtraClass ec1 = ExtraClass("Test");
	ec1.printData();
}
