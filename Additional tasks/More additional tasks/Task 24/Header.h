
#ifndef HEADER
#define HEADER

#include <iostream>
#include <cmath>

class Rat {
private:
	int num;
	int den;

public:
	Rat(int = 0, int = 1);
	Rat(const Rat&);
	Rat sum(const Rat&) const;
	Rat mult(const Rat&) const;
	Rat sub(const Rat&) const;
	Rat div(const Rat&) const;
	void print() const;
	int numer() const;
	int denom() const;
	void setNum(int);
	void setDen(int);
};

Rat operator+ (const Rat&, const Rat&);
Rat operator* (const Rat&, const Rat&);
Rat operator- (const Rat&, const Rat&);
Rat operator/ (const Rat&, const Rat&);

#endif // !HEADER

