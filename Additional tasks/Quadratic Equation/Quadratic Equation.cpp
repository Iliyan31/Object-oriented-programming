
#include "quadraticEquation.h"

void Complex::create_equation(Complex& c) {
	std::cout << "Please enter the value of a: ";
	std::cin >> c.a;
	std::cout << "Please enter the value of b: ";
	std::cin >> c.b;
	std::cout << "Please enter the value of c: ";
	std::cin >> c.c;
	std::cout << std::endl;
}

void Complex::show_equation(const Complex& c) {
	std::cout << "The equation is: " << c.a << "x^2 " <<"+ "<< c.b
		<< "x + " << c.c << " = 0";
	std::cout << std::endl;
}

void Complex::solve_equation(Complex& c) {

	double D, x1, x2;
	D = ((c.b) * (c.b)) - (4 * c.a * c.c);
	if (D > 0) {
		x1 = (-c.b + sqrt(D)) / (2 * c.a);
		print_number(x1);
		x2 = (-c.b - sqrt(D)) / (2 * c.a);
		print_number(x2);
	}
	else if (D == 0) {
		x1 = x2 = (-c.b) / (2 * c.a);
		print_number(x1);
	}
	else {
		D *= -1;
		Complex x1, x2;
		x1.create_complex_number2((-c.b / (2 * c.a)), (sqrt(D)));
		x1.show_complex_numbers2();
		x2.create_complex_number2((-c.b / (2 * c.a)), -(sqrt(D)));
		x2.show_complex_numbers2();
	}
}

void Complex::print_number(double& num) {
	std::cout << "The x of the equation is: " << num << std::endl;
}