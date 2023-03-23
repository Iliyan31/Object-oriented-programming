#pragma once

#include <iostream>

class Complex {
private:
	int real;
	int imaginary;
public:
	void create_complex_number(Complex& c);
	void show_complex_numbers(const Complex& c);
	void add_complex_numbers(const Complex& c1, const Complex& c2);
	void show_complex_add_numbers(const int realPart, const int imaginaryPart);
	void multiply_complex_numbers(const Complex& c1, const Complex& c2);
	void show_complex_multiply_numbers(const int realPart, const int imaginaryPart);
};