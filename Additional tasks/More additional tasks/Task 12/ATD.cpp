
#include "Header.h"

// НОД на две числа
int gcd(int a, int b) {
	while (a != b) {
		if (a > b) a -= b;
		else b -= a;
	}
	return a;
}

int abs1(int a) {
	if (a < 0) return (a *= -1);
	return a;
}

void Rational::makerat(int a, int b) {
	if (a == 0) {
		num = 0;
		den = 1;
	}
	else {
		int g = gcd(abs1(a), abs1(b));
		if (a > 0 && b > 0 || a < 0 && b < 0) {
			num = abs1(a) / g;
			den = abs1(b) / g;
		}
		else {
			num = -abs1(a) / g;
			den = abs(b) / g;
		}
	}
}

int Rational::numer() const {
	return num;
}

int Rational::denom() const {
	return den;
}

void Rational::printRational() const {
	std::cout << num << "/" << den << std::endl;
}

bool equal(const Rational& x, const Rational& y) {
	return x.numer() * y.denom() == x.denom() * y.numer();
}

bool grthan(const Rational& x, const Rational& y) {
	return x.numer() * y.denom() > x.denom() * y.numer();
}

Rational maxRational(int size, Rational x[]) {
	Rational max = x[0];
	for (int i = 0; i < size; i++) {
		if (grthan(x[i], max)) max = x[i];
	}
	return max;
}

void sortRationalDescending(int size, Rational x[]) {
	for (int i = 0; i < size - 1; i++) {
		int k = i;
		Rational max = x[i];
		for (int j = 0; j < size; j++) {
			if (grthan(x[i], max)) {
				k = j;
				max = x[j];
			}
		}
		x[k] = x[i];
		x[i] = max;
	}
}