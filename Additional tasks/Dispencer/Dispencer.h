#pragma once

#include <iostream>

#define MAX_SIZE_CUP 1000

class Dispencer {
private:
	unsigned int current_dispencer;
	unsigned int max_dispencer;
public:
	void create_dispencer(Dispencer& d);
	void show_dispencer(const Dispencer& d);
	void create_glass(unsigned int& size);
	unsigned int fill_glass(const Dispencer& d, unsigned int& capacity);
	void fill_dispencer(Dispencer& d, unsigned int& capacity);
	//void show_new_dispencer(const Dispencer& d);
};


