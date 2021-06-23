
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
}

Fraction::Fraction(Fraction* pOther) : Fraction(*pOther) {
}

/*
float Fraction::asFloat(void) const {
	return (float)(1.0*numerator / denominator);
	//Ratio r = Ratio();
	//r.r = f;
}
*/

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

Fraction& Fraction::operator=(const Fraction& f) {
	this->setNumerator(f.getNumerator());
	this->setDenominator(f.getDenominator());
	return *this;
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
	numerator++;
	//this->setNumerator(this->getNumerator() + 1);
	return copy;
}

Fraction Fraction::operator++() {
	numerator++;
	//this->setNumerator(this->getNumerator() + 1);
	return this;
}

Fraction Fraction::operator--(int n) {
	Fraction copy(this);
	numerator--;
	//this->setNumerator(this->getNumerator() - 1);
	return copy;
}

Fraction Fraction::operator--() {
	numerator--;
	//this->setNumerator(this->getNumerator() - 1);
	return this;
}

void Ratio::setRatio(Fraction& f) {
	float fval = (float)(f.numerator*1.0 / f.denominator);
	//float fval = f.asFloat();
	this->r = fval;
}

void Ratio::showRatio() {
	cout << "Ratio: " << this->r << endl;
}

Fraction Fraction::operator+(Fraction& other) {
	numerator = numerator + other.numerator;
	denominator = denominator + other.denominator;
	return this;
	/*
	return Fraction(numerator + other.numerator,
		denominator + other.denominator);
	*/
}
Fraction Fraction::operator-(Fraction& other) {
	numerator = numerator - other.numerator;
	denominator = denominator - other.denominator;
	return this;
	/*
	return Fraction(numerator - other.numerator,
		denominator - other.denominator);
	*/
}
Fraction Fraction::operator*(Fraction& other) {
	numerator = numerator * other.numerator;
	denominator = denominator * other.denominator;
	return this;
	/*
	return Fraction(numerator * other.numerator,
		denominator * other.denominator);
	*/
}
Fraction Fraction::operator/(Fraction& other) {
	numerator = numerator / other.numerator;
	denominator = denominator / other.denominator;
	return this;
	/*
	return Fraction(numerator / other.numerator,
		denominator / other.denominator);
	*/
}

Fraction Fraction::operator+=(const Fraction& other) {
	//numerator = numerator + other.numerator;
	//denominator = denominator + other.denominator;
	return Fraction(numerator + other.numerator, denominator + other.denominator);
}
Fraction Fraction::operator-=(const Fraction& other) {
	numerator = numerator - other.numerator;
	denominator = denominator - other.denominator;
	return Fraction(numerator, denominator);
}
Fraction Fraction::operator*=(const Fraction& other) {
	numerator = numerator * other.numerator;
	denominator = denominator * other.denominator;
	return Fraction(numerator, denominator);
}
Fraction Fraction::operator/=(const Fraction& other) {
	numerator = numerator / other.numerator;
	denominator = denominator / other.denominator;
	return Fraction(numerator, denominator);
}

int Fraction::operator[](int index) {
	switch (index) {
	case 1:
		return numerator;
	case 2:
		return denominator;
	default:
		return 0;
	}
}
