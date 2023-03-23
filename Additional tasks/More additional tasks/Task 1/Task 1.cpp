
#include <iostream>
#include <iomanip>  // setw - set fileld width

struct Rectangle {
	int length;
	int width;
};

// a)
void print_rectangle(Rectangle r) {
	std::cout << std::setw(10) << r.length << std::setw(10) << r.width << std::endl;
}

// b)
void init_rectangle(Rectangle& r) {
	do {
		std::cout << "length: ";  std::cin >> r.length;
		std::cout << "width: ";   std::cin >> r.width;
	} while (r.length <= 0 || r.width <= 0);
}

// c)
Rectangle init_rectangle() {
	Rectangle r;
	do {
		std::cout << "length: ";  std::cin >> r.length;
		std::cout << "width: ";   std::cin >> r.width;
	} while (r.length <= 0 || r.width <= 0);
	return r;
}

int main() {
	return 0;
}