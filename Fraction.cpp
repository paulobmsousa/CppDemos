
#include <iostream> // for std::cout
#include "Fraction.h" // for class Fraction{}
using namespace std;

//now it knows class Fraction{}

Fraction::Fraction() : Fraction(0) {}


Fraction::Fraction(int n, int d) { //default 0/1
	count++;
	setNumerator(n);
	setDenominator(d);
}

Fraction::Fraction(Fraction& other) :
	Fraction(other.getNumerator(), other.getDenominator()) {
	//std::cout << "Copying from:" << &other << std::endl;
}

Fraction::Fraction(Fraction* pOther) : Fraction(*pOther) {
	//std::cout << "Copying from:" << pOther << std::endl;
}

//setNumerator and getNumerator are Fraction:: functions:
void Fraction::setNumerator(int n) {
	numerator = n;
}

int Fraction::getNumerator(void) const {
	return numerator;
}

void Fraction::setDenominator(int d) {
	denominator = d;
}

int Fraction::getDenominator(void) const {
	return denominator;
}

float Fraction::asFloat(void) const {
	return (float)(numerator/denominator);
}

ostream& operator<<(ostream& out, const Fraction& f) {
	out << f.getNumerator()
		<< " / " << f.getDenominator();
	return out;
}

istream& operator>>(istream& in, Fraction& f) {
	int num, den;
	cout << "Enter a numerator first, then denominator" << endl;
	cin >> num;
	cin >> den;
	f.setNumerator(num);
	f.setDenominator(den);
	return in;
}

const Fraction& Fraction::operator=(const Fraction& f) {
	this->setNumerator(f.getNumerator());
	this->setDenominator(f.getDenominator());
	return this;
}

bool Fraction::operator==(const Fraction& f) {
	bool isEqual = false;
	/*
	isEqual = (this->getNumerator() == f.getNumerator() &&
		this->getDenominator() == f.getDenominator());
	*/
	isEqual = (this->asFloat() == f.asFloat());
	return isEqual;
}

bool Fraction::operator!=(const Fraction& f) {
	return !(operator == (f));
}

Fraction Fraction::operator++(int n) {
	Fraction copy(this);
	this->setNumerator(this->getNumerator() + 1);
	return copy;
}

Fraction Fraction::operator++() {
	this->setNumerator(this->getNumerator() + 1);
	return this;
}
