
#include "quadraticEquation.h"

void Complex::create_complex_number(Complex& c) {
	std::cout << "Please insert the real part: ";
	std::cin >> c.real;
	std::cout << "Please insert the imaginery part: ";
	std::cin >> c.imaginary;
	std::cout << std::endl;
}

void Complex::show_complex_numbers(const Complex& c) {
	std::cout << "The complex number is: " << c.real << "+"
		<< c.imaginary << "i" << std::endl;
	std::cout << std::endl;
}

void Complex::add_complex_numbers(const Complex& c1, const Complex& c2) {
	int realPart = c1.real + c2.real;
	int imaginaryPart = c1.imaginary + c2.imaginary;
	show_complex_add_numbers(realPart, imaginaryPart);
}

void Complex::show_complex_add_numbers(const int realPart, const int imaginaryPart) {
	std::cout << "Addition of the two numbers is: " << realPart << "+" << imaginaryPart << "i" << std::endl;
}


void Complex::multiply_complex_numbers(const Complex& c1, const Complex& c2) {
	int realPart = c1.real * c2.real - c1.imaginary * c2.imaginary;
	int imaginaryPart = c1.real * c2.imaginary + c1.imaginary * c2.real;
	show_complex_multiply_numbers(realPart, imaginaryPart);
}

void Complex::show_complex_multiply_numbers(const int realPart, const int imaginaryPart) {
	std::cout << "Multiplication of the two numbes is: " << realPart << "+" << imaginaryPart << "i" << std::endl;
}

void Complex::create_complex_number2(double real, double imaginary) {
	this->real = real;
	this->imaginary = imaginary;
}

void Complex::show_complex_numbers2() const {
	std::cout << "The complex number is: " << real << "+"
		<< imaginary << "i" << std::endl;
	std::cout << std::endl;
}