// Week1.cpp : Defines the entry point for the application.
//

#include <iostream>
#include "Week4.h"
#include "../Fraction.h"

using namespace std;

// Static Initialization
int Fraction::count = 0;
const static int count3 = 0;

int week4() {
#pragma message("Week 4 Lab ..................................")
	cout << "Week 4 Lab .................................." << endl;
	foo(1, 2, 3);
	testFrac();
	return 0;
}

void testFrac() {
	cout << "testFrac()..." << endl;
	Fraction ambig = Fraction(); //must be line 13
	Fraction f1(5); //d = 1 by default
	Fraction refObject(f1); //copy f by reference
	Fraction pointObject(&f1);
	printFraction(f1); //hidden &f
	Fraction f2(5, 1);
	printFractionNew(&f2);
	int num = addNumerators(f1, f2);
	cout << "Numerators: " << num << endl;
	Fraction f3 = sum(f1, f2);
	printFraction(f3); //hidden &f
	cout << "Fraction count: " << Fraction::count << endl;
}

void printFraction(Fraction& f) {
	cout << "Fraction at address:" << &f
		<< " Numerator:" << f.getNumerator()
		<< " Denominator:" << f.getDenominator() << endl;
}


void printFractionNew(Fraction *f) {
	cout << "Fraction at address:" << f
		<< " Numerator:" << f->getNumerator()
		<< " Denominator:" << f->getDenominator() << endl;
}

int addNumerators(Fraction f1, Fraction f2) {
	return f1.getNumerator() + f2.getNumerator();
}

Fraction sum(Fraction f1, Fraction f2) {
	Fraction f = Fraction();
	f.setNumerator(f1.getNumerator() * f2.getDenominator() +
		f2.getNumerator() * f1.getDenominator());
	f.setDenominator(f1.getDenominator() * f2.getDenominator());
	return f;
}

void foo(int a, int b, int c, int d) {
	cout << "foo()..." << endl;
	cout << "a=" << a << ", "
		<< "b=" << b << ", "
		<< "c=" << c << ", "
		<< "d=" << d << endl;
}
