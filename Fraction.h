#pragma once

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Fraction {
private:
	int numerator, denominator;
	const static int num; // initialize here needs const
	friend class Ratio;
public:
	static int count;
	const static int count2 = 0;
	Fraction(); // chaining to other
	Fraction(int, int = 1); // d = 1
	Fraction(Fraction&);
	Fraction(Fraction*);

	/*
	inline int getNumerator(void) const;
	inline int getDenominator(void) const;
	inline void setNumerator(int);
	inline void setDenominator(int);
	*/
	
	inline float Fraction::asFloat(void) const {
		return (float)(1.0 * numerator / denominator);
	}

	inline int Fraction::getNumerator(void) const {
		return numerator;
	}

	inline int Fraction::getDenominator(void) const {
		return denominator;
	}

	inline void Fraction::setNumerator(int n) {
		numerator = n;
	}

	inline void Fraction::setDenominator(int d) {
		denominator = d;
	}

	friend ostream& operator<<(ostream& out, const Fraction& f);
	friend istream& operator>>(istream& in, Fraction& f);

	Fraction& Fraction::operator=(const Fraction& f);
	bool Fraction::operator==(const Fraction& f);
	bool Fraction::operator!=(const Fraction& f);
	// Self operators
	Fraction Fraction::operator++();
	Fraction Fraction::operator++(int n);
	Fraction Fraction::operator--();
	Fraction Fraction::operator--(int n);
	// Bi operators
	Fraction Fraction::operator+(Fraction&);
	Fraction Fraction::operator-(Fraction&);
	Fraction Fraction::operator*(Fraction&);
	Fraction Fraction::operator/(Fraction&);
	Fraction Fraction::operator+=(const Fraction&);
	Fraction Fraction::operator-=(const Fraction&);
	Fraction Fraction::operator*=(const Fraction&);
	Fraction Fraction::operator/=(const Fraction&);
	// Index operator
	int Fraction::operator[](int);

};

class Ratio {
private:
	float r;
public:
	void setRatio(Fraction& f);
	void showRatio();
	friend float Fraction::asFloat(void) const;
	friend void showAll(Ratio&);
};
