
#include "Dispencer.h"

void Dispencer::create_dispencer(Dispencer& d) {
	std::cout << "Please insert the size of the dispencer: ";
	std::cin >> d.max_dispencer;
	//std::cout << std::endl;
	do {
		std::cout << "Please insert the current size of the dispencer: ";
		std::cin >> d.current_dispencer;
	} while (d.current_dispencer > d.max_dispencer);
}

void Dispencer::show_dispencer(const Dispencer& d) {
	std::cout << "The max capacity of the dispencer is: " << d.max_dispencer << std::endl;
	std::cout << "The current capacity of the dispencer is: " << d.current_dispencer << std::endl;
}

void Dispencer::create_glass(unsigned int& size) {
	do {
		std::cout << "Please insert the capacity of the glass from 350 to "<<MAX_SIZE_CUP<<": ";
		std::cin >> size;
		/*std::cout << std::endl;*/
	} while (size < 350 || size > MAX_SIZE_CUP);
}

unsigned int Dispencer::fill_glass(const Dispencer& d, unsigned int& capacity) {
	unsigned int size = 0;
	create_glass(size);
	unsigned int new_size = 0;

	if (d.current_dispencer >= size) new_size = size;
	else new_size = d.current_dispencer;

	do {
		std::cout << "Please insert the ml-s of the glass from 0 to " << new_size << ": ";
		std::cin >> capacity;
		std::cout << std::endl;
	} while (capacity > size || capacity > d.current_dispencer);
	if (capacity > d.current_dispencer) {
		std::cout << "There is not enough water in the dispencer \n";
		return -1;
	}
	std::cout << "The max capacity of the glass is: " << size << std::endl;
	std::cout << "The capacity of the glass is: ";
	return capacity;
}

void Dispencer::fill_dispencer(Dispencer& d, unsigned int& capacity) {
	unsigned int last_water = d.current_dispencer - capacity;
	do {
		std::cout << "Please insert the ml-s of the dispencer from 0 to " << d.max_dispencer - last_water << ": ";
		std::cin >> d.current_dispencer;
		std::cout << std::endl;
	} while (d.current_dispencer > d.max_dispencer - last_water);
	d.current_dispencer += last_water;
}

//void Dispencer::show_new_dispencer(const Dispencer& d) {
//	std::cout << "New capacity of the dispencer is: " << d.current_dispencer << std::endl;
//}