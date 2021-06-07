#pragma once

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Fraction {
private:
	int numerator, denominator;
	const static int num; // initialize here needs const

public:
	static int count;
	const static int count2 = 0;
	Fraction(); // chaining to other
	// Fraction can have  1, or 2 parameters
	Fraction(int, int = 1); // d = 1
	Fraction(Fraction&);
	Fraction(Fraction*);

	void setNumerator(int);
	int getNumerator(void) const;

	void setDenominator(int);
	int getDenominator(void) const;

	float asFloat(void) const;

	friend ostream& operator<<(ostream& out, const Fraction& f);
	friend istream& operator>>(istream& in, Fraction& f);

	const Fraction& Fraction::operator=(const Fraction& f);
	bool Fraction::operator==(const Fraction& f);
	bool Fraction::operator!=(const Fraction& f);
	Fraction Fraction::operator++();
	Fraction Fraction::operator++(int n);

};
