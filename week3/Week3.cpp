// Week1.cpp : Defines the entry point for the application.
//

#include <iostream>
#include "Week3.h"
#include "Fraction.h"

using namespace std;

int week3() {
#pragma message("Week 3 Lab ..................................")
	cout << "Week 3 Lab .................................." << endl;
	testFrac();
	return 0;
}

void testFrac() {
	foo(1, 2, 3, 4);
	Fraction ambig = Fraction(); //must be line 13
	Fraction f(5); //d = 1 by default
	Fraction refObject(f); //copy f by reference
	Fraction pointObject(&f);
	printFraction(f); //hidden &f
}

void printFraction(Fraction& f) {
	cout << "Fraction at address:" << &f
		<< " Numerator:" << f.getNumerator()
		<< " Denominator:" << f.getDenominator() << endl;
}

void foo(int a, int b, int c = 20, int d = 20) {}
