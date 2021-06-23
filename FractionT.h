#pragma once

#ifndef _FractionT_h_
#define _FractionT_h_


#include <iostream>
#include <fstream>

using namespace std;

template <class T>
class FractionT {
	T numerator, denominator;
	friend ostream& operator<<(ostream& out, const FractionT& f);
	friend istream& operator>>(istream& in, FractionT& f);

public:

	typedef T objtype;

	inline FractionT(T n, T d = 1) {
		if (d == 0)
			throw string("divide by 0 exception");
		numerator = n;
		denominator = d;
	}

	inline void setNumerator(T n) {
		numerator = n;
	}

	inline T getNumerator(void) const {
		return numerator;
	}

	inline void setDenominator(T d) {
		denominator = d;
	}

	inline T getDenominator(void) const {
		if (denominator == 0)
			return 1;
		else
			return denominator;
	}

	inline float asFloat(void) {
		return (float)getNumerator() / getDenominator();
	}

	inline FractionT operator=(const FractionT& other) {
		numerator = other.numerator;
		if (other.denominator == 0)
			denominator = 1;
		else
			denominator = other.denominator;
		return other;
	}

	FractionT operator+(const FractionT& other) const;

	FractionT operator+(int other);

	bool operator==(const FractionT& other) const {
		return numerator == other.numerator && denominator == other.denominator;
	}

	inline FractionT operator+=(const FractionT& other) {
		numerator *= other.denominator;
		numerator += (other.numerator * denominator);
		denominator *= other.denominator;
		return FractionT(numerator, denominator);
	}

	int operator[ ] (int index) {
		switch (index) {
		case 1:
			return numerator;
			break;
		case 2:
			return denominator;
			break;
		default:
			return 0;
		}
	}

	FractionT operator++() {
		numerator += denominator;
		return FractionT(numerator, denominator);
	}

	FractionT operator++(int i) {
		FractionT copy(numerator, denominator);
		numerator += denominator;
		return copy;
	}

	inline bool operator!() {
		if (numerator == 0)
			return true;
		else
			return false;
	}
};


#endif
