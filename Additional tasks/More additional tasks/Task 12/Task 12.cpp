
#include "Header.h"

Rational Rational::sumRat(const Rational& r1, const Rational& r2) {
	Rational r;
	r.makerat(r1.numer() * r2.denom() + r2.numer() * r1.denom(), r1.denom() * r2.denom());
	return r;
}

Rational Rational::subtract(const Rational& r1, const Rational& r2) {
	Rational r;
	r.makerat(r1.numer() * r2.denom() - r2.numer() * r1.denom(), r1.denom() * r2.denom());
	return r;
}

Rational Rational::multRat(const Rational& r1, const Rational& r2) {
	Rational r;
	r.makerat(r1.numer() * r2.numer(), r1.denom() * r2.denom());
	return r;
}

Rational Rational::quotRat(const Rational& r1, const Rational& r2) {
	Rational r;
	r.makerat(r1.numer() * r2.denom(), r1.denom() * r2.numer());
	return r;
}

void Rational::rational_system(const Rational& a, const Rational& b,
	const Rational& c, const Rational& d, const Rational& e, const Rational& f) {

	Rational det = subtract(multRat(a,d), multRat(c,b), zero)

}
