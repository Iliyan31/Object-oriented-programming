
#ifndef HEADER
#define HEADER

#include <iostream>

class N {
private:
	int a;
	double b;
public:
	N(int = 5, double = 2.5);
	~N();
	void display() const;
};

N::N(int x, double y) : a(x), b(y) {}

N::~N() {
	printf("~N \n");
}

void N::display() const {
	std::cout << a << " " << b << std::endl;
}

#endif // !HEADER
