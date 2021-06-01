#pragma once

#include <string>

class Fraction {
private:
	int numerator, denominator;
	const static int num = 0; //initialize here needs const

public:
	Fraction();//chaining to other
	//can have  1, or 2 parameters
	Fraction(int, int = 1); // d = 1
	Fraction(Fraction&);
	Fraction(Fraction*);

	void setNumerator(int);
	int getNumerator(void);

	void setDenominator(int);
	int getDenominator(void);

	float asFloat(void);
};
