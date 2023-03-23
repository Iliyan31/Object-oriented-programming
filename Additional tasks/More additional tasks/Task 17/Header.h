 
#ifndef HEADER
#define HEADER

#include <iostream>

class M {
private:
	int a;
	double b;
public:
	M(int = 5, double = 2.5);
	void set(int, double);
	void display() const;
};

M::M(int x, double y) : a(x), b(y) {}

void M::set(int x, double y) {
	this->a = x;
	this->b = y;
}

void M::display() const {
	std::cout << a << " " << b<<std::endl;
}

#endif // !HEADER

