#pragma once

#include <iostream>

const int MAX_SIZE1 = 10;

class Complex {
private:
	int Rz;
	int Im;
public:
	Complex Horner(int size, Complex arr[], Complex x);
};