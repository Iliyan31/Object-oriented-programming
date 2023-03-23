
#include "Header.h"

int main() {
	int a, b;
	std::cout << "Please insert a and b: ";
	std::cin >> a >> b;
	Rat r(a, b);
	int c, d;
	do {
		std::cout << "Please insert c and d: ";
		std::cin >> c >> d;
	} while (c == 0 || d == 0);

	Rat s(c, d);
	Rat sum = r + s;
	Rat sub = r - s;
	Rat mult = r * s;
	Rat div = r / s;

	r.print(); printf(" + "); s.print(); printf(" = "); sum.print(); std::cout << std::endl;
	r.print(); printf(" - "); s.print(); printf(" = "); sub.print(); std::cout << std::endl;
	r.print(); printf(" * "); s.print(); printf(" = "); mult.print(); std::cout << std::endl;
	r.print(); printf(" / "); s.print(); printf(" = "); div.print(); std::cout << std::endl;

	r.setNum(5); r.setDen(7);
	r.print();
	std::cout << std::endl;

	return 0;
}