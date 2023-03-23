
#include "Header.h"


int main() {
	Complex x, arr[MAX_SIZE1];
	double p, q;
	std::cout << "Re, Im? ";
	std::cin >> p >> q;
	x.cerate(p, q);
	std::cout << "n = ";
	int size;
	std::cin >> size;
	for (int i = 0; i < size; i++) {
		std::cout << "Re, Im? ";
		std::cin >> p >> q;
		arr[i].create(p, q);
	}
	Horner(size, arr, x).print();
	return 0;
}