#include <iostream>
#include "Week5.h"
#include "../Fraction.h"

using namespace std;

int week5() {
#pragma message("Week 5 Lab ..................................")
	cout << "Week 5 Lab .................................." << endl;
	testReadWrite();
	testComparison();
	testOperators();
	return 0;
}

void write(Fraction f) {
	cout << f << endl;
}

void read(Fraction f) {
	cin >> f;
}

void testReadWrite() {
	cout << "testReadWrite()..." << endl;
	Fraction f = Fraction();
	cin >> f;
	cout << f;
	cout << endl;
}

void testComparison() {
	cout << "testComparison()..." << endl;
	Fraction f1 = Fraction(5);
	Fraction f2 = Fraction(4, 3);
	cout << "f1 = " << f1 << ", f2 = " << f2 << endl;
	if (f1 == f2)
		cout << "F1 and F2 are equal" << endl;
	else 
		cout << "F1 and F2 are different" << endl;
	f2 = f1;
	cout << "f1 = " << f1 << ", f2 = " << f2 << endl;
	if (f1 != f2)
		cout << "F1 and F2 are different" << endl;
	else
		cout << "F1 and F2 are equal" << endl;
	Fraction f3 = Fraction(10, 2);
	cout << "f1 = " << f1 << ", f3 = " << f3 << endl;
	if (f1 == f3)
		cout << "F1 and F3 are equal" << endl;
	else
		cout << "F1 and F3 are different" << endl;
}

void testOperators() {
	cout << "testOperators()..." << endl;
	Fraction f1 = Fraction(5);
	Fraction f2 = f1++;
	Fraction f3 = ++f1;
	cout << "f1 = " << f1 << ", f2 = " << f2 << ", f3 = " << f3 << endl;
	Fraction f4 = Fraction(7);
	Fraction f5 = Fraction(5, 8);
	f4--;
	--f5;
	cout << "f4 = " << f4 << ", f5 = " << f5 << endl;
	Fraction f6 = Fraction();
	f6--;
	cout << "f6 = " << f6 << endl;
}

