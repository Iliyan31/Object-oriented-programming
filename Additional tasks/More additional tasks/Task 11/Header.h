#pragma once

#include <iostream>

class Rational {
private :
	int num;
	int den;
public:
	void makerat(int a, int b);
	int numer() const;
	int denom() const;
	void printRational() const;
};