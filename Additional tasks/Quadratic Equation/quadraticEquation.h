#pragma once

#include <iostream>
#include <cmath>

class Complex {

public:
	void create_equation(Complex& c);
	void show_equation(const Complex& c);
	void solve_equation(Complex& c);


public:
	void create_complex_number(Complex& c);
	void show_complex_numbers(const Complex& c);
	void add_complex_numbers(const Complex& c1, const Complex& c2);
	void show_complex_add_numbers(const int realPart, const int imaginaryPart);
	void multiply_complex_numbers(const Complex& c1, const Complex& c2);
	void show_complex_multiply_numbers(const int realPart, const int imaginaryPart);
	void create_complex_number2(double real, double imaginary);
	void print_number(double& num);
	void show_complex_numbers2() const;

private:
	int real;
	int imaginary;

	double a;
	double b;
	double c;
};
