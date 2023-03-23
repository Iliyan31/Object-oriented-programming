
#ifndef HEADER
#define HEADER

#include <iostream>

class L {
private:
	int a; 
	double b;
public:
	L(int = 5, double = 2.5);
	void display() const;
};

L::L(int x, double y) : a(x), b(y) {}

void L::display() const {
	std::cout << a << " " << b << std::endl;
}

#endif // !HEADER
