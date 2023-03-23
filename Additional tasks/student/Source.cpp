
#include "Header.h"

int main() {
	Student s;
	s.print();
	Student b("Iliyan", 12345, 3.2);
	b.print();
	Student c = b;
	c.print();

	b = c;
	c.print();
	b.print();

	return 0;
}