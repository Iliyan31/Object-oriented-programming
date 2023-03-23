
#include "Planet.h"

int main() {
	Planet p;
	/*p.create_planet(p);
	std::cout << std::endl;
	p.show_planet(p);*/
	Planet** arr = new Planet * [MAX_size];
	for (int i = 0; i < MAX_size; i++) {
		arr[i] = new Planet[MAX_size];
	}
	p.groupOfPlanets(1, *arr);
	std::cout << std::endl;
	p.sortPlanets(1, arr);
	p.show_planets_data(1, arr);


	for (int i = 0; i < MAX_size; i++) {
		delete[] arr[i];
	}
	delete[] arr;

	return 0;
}