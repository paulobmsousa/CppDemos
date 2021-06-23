#include <iostream>
#include <stdlib.h>     // srand, rand
#include <chrono>       // now, duration
#include <cmath>       // pow
#include "Week7.h"
#include "../Fraction.h"
#include "../FractionT.h"

using namespace std;

int week7() {
#pragma message("Week 7 Lab ..................................")
	cout << "Week 7 Lab .................................." << endl;
	testInline();
	/*
	testVirtualFunctions();
	testVirtualDestructor();
	testInline();
	testInheritance();
	testRandom();
	testTime();
	testCasting();
	testDynamicCasting();
	*/
	testTemplate();
	return 0;
}

// TEST VIRTUAL ..............................................

void testVirtualFunctions() {
	ChildA* pointerChild = new ChildC();
	pointerChild->myFunction1();
	pointerChild->myFunction2();
}

void testVirtualDestructor() {
	ChildA* pointerChild = new ChildC();
	delete pointerChild;
	cout << "End of program" << endl;
}


// TEST INLINE ..............................................

int inline Max (int x, int y) {
	return (x > y) ? x : y;
}

void testInline() {
	cout << "testInline()..." << endl;
	Fraction f = Fraction(5, 7);
	cout << "Fraction: " << f << ", float: " << f.asFloat() << endl;
	int a, b;
	a = 20, b = 10;
	cout << "Max (" << a << "," << b << "): " << Max(a, b) << endl;
}


// MULTIPLE INHERITANCE ..........................................

void testInheritance() {
	cout << "testInheritance()..." << endl;
	Root root = Root();
	ChildA objA = ChildA();
	ChildB objB = ChildB();
	ChildC objC = ChildC();
	cout << "r from Root = " << root.r << endl;
	cout << "r inherited from ChildA = " << objA.r << endl;
	cout << "r inherited from ChildB = " << objB.r << endl;
	//cout << "r inherited from ChildC = " << objC.r << endl;
	cout << "r inherited from ChildC = " << objC.ChildA::r << endl;
	cout << "r inherited from ChildB = " << objC.ChildB::r << endl;
	//cout << "r inherited from ChildC = " << objC.ChildC::r << endl;
	cout << "ChildC.a = " << objC.a
		<< ", ChildC.b = " << objC.b
		<< ", ChildC.c = " << objC.c << endl;
	objC.test();
	cout << "ChildC.a = " << objC.a
		<< ", ChildC.b = " << objC.b
		<< ", ChildC.c = " << objC.c << endl;
}


// TEST RANDOM ..................................................

void testRandom() {
	const int MAX = 10;
	cout << "testRandom()..." << endl;
	srand((unsigned int)time(NULL)); //initialize random seed
	int val = 1;
	int attempts = 0;
	while (val != MAX) {
		val = rand() % MAX + 1;
		cout << "Rand value: " << val << endl;
		attempts++;
	}
	cout << "Number of attempts: " << attempts << endl;
}

// TEST TIME ..................................................

void testTime() {
	int numRunning = 0, cont = 0, maxValue, desiredNumber, currentVal, numAttempts;
	double timeout;
	cout << "Enter the number of runnings: ";
	cin >> numRunning;
	cout << "Enter the max value: ";
	cin >> maxValue;
	cout << "Enter the desired number: ";
	cin >> desiredNumber;
	while (cont < numRunning) {
		cont++;
		currentVal = 0;
		numAttempts = 0;
		auto start = std::chrono::system_clock::now();
		while (currentVal != desiredNumber) {
			currentVal = rand() % maxValue + 1;
			numAttempts++;
		}
		auto end = std::chrono::system_clock::now();
		std::chrono::duration<double> diff = end - start;
		timeout = diff.count()*1000000;
		cout << "Exec: " << cont << " - timeout: " << timeout << ", numAttempts = " << numAttempts << endl;
	}
}

// TEST CASTING .................................................

class Temp {
public:
	int a;
	unsigned int b : 1, c : 1, d : 30;
};


void testCasting() {
	Temp a;
	int size = sizeof(a);
	cout << "size: " << size << endl;
	a.a = a.b = a.c = a.d = pow(2, 30) - 1;
	cout << "a=" << a.a << ", b=" << a.b << 
		", c=" << a.c << ", d=" << a.d << endl;
	a.a++;
	a.b++;
	a.c++;
	a.d++;
	cout << "a=" << a.a << ", b=" << a.b <<
		", c=" << a.c << ", d=" << a.d << endl;
	string s = "Paulo";
	string* pstring = &s;
	cout << *pstring << endl;
	///pstring = (string*)&a;
	cout << *pstring << endl;
}


class Base {
	public: void print() { cout << "Base" << endl; }
};
class Derived : public Base {
	public: void print() { cout << "Derived" << endl; }
};
class MyClass {
	public: void print() { cout << "MyClass" << endl; }
};

void testStaticCasting() {
	Derived* d = new Derived;
	d->print();
	Base* b = static_cast<Base*>(d); // this line will work properly
	b->print();
	///MyClass* x = static_cast<MyClass*>(d); // ERROR will be generated during compilation
}

class MyClass1 {
public:
	virtual void print()const {
		cout << "This is from MyClass1" << endl;
	}
};
class MyClass2 {
public:
	virtual void print()const {
		cout << "This is from MyClass2" << endl;
	}
};
class MyClass3 : public MyClass1, public MyClass2 {
public:
	void print()const {
		cout << "This is from MyClass3" << endl;
	}
};

void testDynamicCasting() {
	MyClass1* a = new MyClass1;
	MyClass2* b = new MyClass2;
	MyClass3* c = new MyClass3;
	a->print();
	b->print();
	c->print();
	b = dynamic_cast<MyClass2*>(a); //This cast will be failed
	if (b)
		b->print();
	else
		cout << "ERROR1: no MyClass2\n";
	a = c;
	a->print(); //Printing from MyClass3
	b = dynamic_cast<MyClass2*>(a); //Successfully casting is done
	if (b)
		b->print();
	else
		cout << "ERROR2: no MyClass2\n";
}

// TEST TEMPLATES ...............................................

template <class A>
A maximum(A first, A second) {
	return (first > second) ? first : second;
}

void testTemplate() {
	// Fractions
	FractionT <int> f1 = FractionT<int>(2, 4);
	cout << "Fraction1: " << f1.getNumerator() << " / " << f1.getDenominator() << endl;
	FractionT <long> f2 = FractionT<long>(2000000, 40000000);
	cout << "Fraction2 (float): " << f2.asFloat() << endl;
	// Max
	int a = maximum(10, 20);
	cout << "maximum1: " << a << endl;
	float b = maximum(23.54f, -35.85f);
	cout << "maximum2: " << b << endl;
}
