
#include "Dispencer.h"


int main() {
	Dispencer d;
	d.create_dispencer(d);
	std::cout << std::endl;

	unsigned int capacity;
	std::cout << d.fill_glass(d, capacity);
	std::cout << std::endl;
	std::cout << std::endl;

	d.fill_dispencer(d, capacity);
	std::cout << std::endl;
	

	d.show_dispencer(d);
	std::cout << std::endl;

	//d.show_new_dispencer(d);
	
	return 0;
}