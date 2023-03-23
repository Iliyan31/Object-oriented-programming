
#include "Header.h"

Fraction::Fraction(int x, int y) : n(x), d(y) {}

int Fraction::getN() const { return n; }

int Fraction::getD() const { return d; }

bool IsFraction(const Fraction& obj) {
	return obj.n % obj.d != 0;
}


int main() {
	int a, b;
	do {
		std::cout << "a, b, (b!=0): ";
		std::cin >> a >> b;
	} while (b == 0);
	Fraction f(a, b);

	if (IsFraction(f)) {
		std::cout << f.getN() << " doesn't divide "
			<< f.getD() << std::endl;
	}
	else {
		std::cout << f.getN() << " divide "
			<< f.getD() << std::endl;
	}
	return 0;
}