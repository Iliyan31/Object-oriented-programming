

#include "ComplexNumbers.h"

int main() {
	Complex c, a, b;
	c.create_complex_number(a);
	c.show_complex_numbers(a);
	c.create_complex_number(b);
	c.show_complex_numbers(b);
	c.add_complex_numbers(a, b);
	c.multiply_complex_numbers(a, b);

	return 0;
}