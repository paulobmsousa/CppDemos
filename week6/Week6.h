#pragma once
#include "../Fraction.h"


// CLASSES FOR VIRTUAL TEST ........................................

class ClassA {
public:
	/*
	void myFunction() {
		cout << "Calling myFunction() from class A" << endl;
	}
	*/
	virtual void myFunction() {
		cout << "Calling myFunction() from class A" << endl;
	}
};

class ClassB : public ClassA {
public:
	virtual void myFunction() override {
		cout << "Calling myFunction() from class B" << endl;
	}
};


class ClassC : public ClassB {
public:
	void myFunction() {
		cout << "Calling myFunction() from class C" << endl;
	}
};

class ClassD : public ClassC {
public:
	void myFunction() {
		cout << "Calling myFunction() from class D" << endl;
	}
};

// FUNCTION DECLARATIONS ........................................

int week6();
void testFriends();
void testMoreOperators();
void showAll(Ratio&);
void testIndex();
void testVirtual();
void testInheritance();
void testVirtualFunctions();
void testVirtualDestructor();
