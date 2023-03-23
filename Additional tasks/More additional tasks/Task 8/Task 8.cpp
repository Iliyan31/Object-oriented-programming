
#include <iostream>
#include <iomanip>

struct Rectangle {
	int length;
	int width;
};

int main() {

	//a)
	Rectangle r = { 15,20 };
	Rectangle* p = &r;

	//b)
	std::cout << std::setw(10) << p->length
		<< std::setw(10) << p->width << std::endl;

	//c)
	p->width;

	return 0;
}