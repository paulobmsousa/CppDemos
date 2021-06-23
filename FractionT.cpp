#include "FractionT.h"

template<class T>
ostream& operator<<(ostream& out, const FractionT<T>& f) {
	out << "Numerator:" << f.numerator
		<< " Denominator:" << f.denominator;
	return out;
}

template<class T>
istream& operator>>(istream& in, FractionT<T>& f) {
	cout << "Enter a numerator first, then denominator" << endl;
	cin >> f.numerator;
	cin >> f.denominator;
	return  in;
}

template<class T>
FractionT<T> FractionT<T>::operator+(const FractionT<T>& other) const {
	return FractionT((numerator * other.denominator) + (denominator * other.numerator),
		denominator * other.denominator);
}

template<class T>
FractionT<T> FractionT<T>::operator+(int other) {
	return FractionT(numerator + (other * denominator), denominator);
}
