#pragma once
#include "../Fraction.h"


// CLASSES FOR MULTIPLE INHERITANCE ........................................

class Root {
	public:
		int r;
};
class ChildA: public Root {
	public:
		int a;
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
	public:
		int b;
		void myFunction1(void) {
			cout << "In B::MyFunction1()" << endl;
		}
};
class ChildC : public ChildA, public ChildB {
	public:
		int c;
		void myFunction1(void) {
			cout << "In C::MyFunction1()" << endl;
		}
		void myFunction2(void) {
			cout << "In C::MyFunction2()" << endl;
		}
		virtual ~ChildC() {
			cout << "Calling destructor from C" << endl;
		}
};

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
