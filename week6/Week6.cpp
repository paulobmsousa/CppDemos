#include <iostream>
#include "Week6.h"
#include "../Fraction.h"

using namespace std;

int week6() {
#pragma message("Week 6 Lab ..................................")
	cout << "Week 6 Lab .................................." << endl;
	//testMoreOperators();
	//testIndex();
	//testFriends();
	//testInline();
	testVirtual();
	testVirtualFunctions();
	testVirtualDestructor();
	return 0;
}


// MORE ABOUT OPERATORS ..............................................

void testMoreOperators() {
	cout << "testMoreOperators()..." << endl;
	Fraction f1(5, 1);
	cout << "f1=" << f1 << endl;
	Fraction f2(1, 3);
	cout << "f2=" << f2 << endl;
	Fraction f3;
	cout << "Operations 1..." << endl;
	f3 = f1 + f2;
	cout << "Sum: " << f3 << endl;
	f3 = f1 - f2;
	cout << "Sub: " << f3 << endl;
	f3 = f1 * f2;
	cout << "Mul: " << f3 << endl;
	f3 = f1 / f2;
	cout << "Div: " << f3 << endl;
	cout << "Operations 2..." << endl;
	cout << "Ori f1: " << f1 << ", f2: " << f2 << endl;
	f1 += f2;
	cout << "Sum f1: " << f1 << ", f2: " << f2 << endl;
	f1 -= f2;
	cout << "Sub f1: " << f1 << ", f2: " << f2 << endl;
	f1 *= f2;
	cout << "Mul f1: " << f1 << ", f2: " << f2 << endl;
	f1 /= f2;
	cout << "Div f1: " << f1 << ", f2: " << f2 << endl;
	cout << "Operations 3..." << endl;
	cout << "Ori f1: " << f1 << ", f2: " << f2 << endl;
	f1.operator+=(f2);
	cout << "Sum f1: " << f1 << ", f2: " << f2 << endl;
	f1.operator-=(f2);
	cout << "Sub f1: " << f1 << ", f2: " << f2 << endl;
	f1.operator*=(f2);
	cout << "Mul f1: " << f1 << ", f2: " << f2 << endl;
	f1.operator/=(f2);
	cout << "Div f1: " << f1 << ", f2: " << f2 << endl;
}

void testIndex() {
	cout << "testIndex()..." << endl;
	Fraction f1(5, 1);
	cout << "f1: " << f1 << endl;
	cout << "f1[0]=" << f1[0] << endl;
	cout << "f1[1]=" << f1[1] << endl;
	cout << "f1[2]=" << f1[2] << endl;
}

// FRIEND OPERATOR ..............................................

void testFriends() {
	cout << "testFriends()..." << endl;
	Fraction f = Fraction(2, 5);
	//cout << "f=" << f << end;
	Ratio r;
	r.setRatio(f);
	r.showRatio();
	showAll(r);
}

void showAll(Ratio& r) {
	cout << "Ratio: " << r.r << endl;
}

// Friend examples: https://www.geeksforgeeks.org/friend-class-function-cpp/

// VIRTUAL FUNCTIONS ..............................................

void testVirtual() {
	cout << "testVirtual()..." << endl;
	ClassA objA;
	ClassB objB;
	ClassC objC;
	ClassD objD;
	objA.myFunction();
	objB.myFunction();
	objC.myFunction();
	objD.myFunction();
}
