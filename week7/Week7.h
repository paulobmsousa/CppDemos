#pragma once

#include <iostream>
using namespace std;

// CLASSES FOR MULTIPLE INHERITANCE ........................................

class Root {
protected:
	int r = 1;
	int a = 2;
public:
	friend void testInheritance();
};

class ChildA : public Root {
protected:
	int a = 0;
public:
	void myFunction1(void) {
		cout << "In A::MyFunction1()" << endl;
	}
	virtual void myFunction2(void) {
		cout << "In A::MyFunction2()" << endl;
	}
	virtual ~ChildA() {
		cout << "Calling destructor from A" << endl;
	}
};
class ChildB : public Root {
protected:
	int a = 3;
	int b = 4;
public:
	void myFunction1(void) {
		cout << "In B::MyFunction1()" << endl;
	}
};
class ChildC : public ChildA, public ChildB {
protected:
	int a = 5;
	int c = 6;
public:
	void myFunction1(void) {
		cout << "In C::MyFunction1()" << endl;
	}
	virtual void myFunction2(void) {
		cout << "In C::MyFunction2()" << endl;
	}
	void test() {
		ChildA::r = 10;
		ChildB::r = 20;
		a = 1;
		b = 2;
		c = 3;
	}
	friend void testInheritance();
	virtual ~ChildC() {
		cout << "Calling destructor from C" << endl;
	}
};

// FUNCTION DECLARATIONS ........................................

int week7();
void testInline(); 
void testInheritance();
void testVirtualFunctions();
void testVirtualDestructor();
void testRandom();
void testTime();
void testTemplate();
void testCasting();
void testStaticCasting();
void testDynamicCasting();
