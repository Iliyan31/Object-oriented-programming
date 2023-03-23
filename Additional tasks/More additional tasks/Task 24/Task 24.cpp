
#include "Header.h"

int gcd(int x, int y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}

Rat::Rat(int n, int d) {
	if (d == 0) {
		printf("Invalid denominator!, It will be replaced with 1. \n");
		this->num = n;
		this->den = 1;
	}
	else {
		if (n == 0) {
			this->num = 0;
			this->den = 1;
		}
		else {
			int g = gcd(abs(n), abs(d));
			if (n > 0 && d > 0 || n < 0 && d < 0) {
				this->num = abs(n) / g;
				this->den = abs(d) / g;
			}
			else {
				this->num = -abs(n) / g;
				this->den = abs(d) / g;
			}
		}
	}
}

Rat::Rat(const Rat& r) : num(r.num), den(r.den) {}

int Rat::numer() const { return num; }
int Rat::denom() const { return den; }

void Rat::print() const {
	std::cout << num << "/" << den;
}
void Rat::setNum(int n) {
	this->num = n;
}

void Rat::setDen(int d) {
	if (d != 0) {
		this->den = d;
	}
	else {
		printf("Invalid denominator!, It will be replaced with 1. \n");
		this->den = 1;
	}
}

Rat Rat::sum(const Rat& r) const{
	return Rat(num * r.den + den * r.num, den * r.den);
}

Rat Rat::sub(const Rat& r) const {
	return Rat(num * r.den - den * r.num, den * r.den);
}

Rat Rat::mult(const Rat& r) const {
	return Rat(num * r.num, den * r.den);
}

Rat Rat::div(const Rat& r) const {
	return Rat(num * r.den, den * r.num);
}

Rat operator+(const Rat& r, const Rat& s) {
	return r.sum(s);
}

Rat operator-(const Rat& r, const Rat& s) {
	return r.sub(s);
}

Rat operator*(const Rat& r, const Rat& s) {
	return r.mult(s);
}

Rat operator/(const Rat& r, const Rat& s) {
	return r.div(s);
}