
#ifndef HEADER
#define HEADER

#include <iostream>

class Fraction {
private: 
	int n, d;
public:
	Fraction(int x = 0, int y = 0);
	int getN() const;
	int getD() const;
	friend bool IsFraction(const Fraction& obj);
};

#endif // !HEADER

