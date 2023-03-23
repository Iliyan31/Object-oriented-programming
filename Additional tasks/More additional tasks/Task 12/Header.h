#pragma once

#include <iostream>
#include <cmath>

class Rational {
private:
	int num;
	int den;
public:
	void makerat(int a, int b);
	int numer() const;
	int denom() const;
	void printRational() const;
public:
	Rational sumRat(const Rational& r1, const Rational& r2);
	Rational subtract(const Rational& r1, const Rational& r2);
	Rational multRat(const Rational& r1, const Rational& r2);
	Rational quotRat(const Rational& r1, const Rational& r2);
	void rational_system(const Rational& a, const Rational& b,
		const Rational& c, const Rational& d, const Rational& e, const Rational& f);
};