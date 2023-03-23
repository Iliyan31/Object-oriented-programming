
#include "Planet.h"

void Planet::create_planet(Planet& p) {
	std::cout << "Please insert the name of the planet: ";
	std::cin >> p.name;
	std::cout << "Please insert the distance of the planet to the sun: ";
	std::cin >> p.dist;
	std::cout << "Please insert the diameter of the planet: ";
	std::cin >> p.diam;
	std::cout << "Please insert the mass of the planet: ";
	std::cin >> p.mass;
}

void Planet::show_planet(const Planet& p) {
	std::cout << "Planet name: " << name << "\nDistance from Sun: " << dist
		<< "\nDiameter: " << diam << "\nMass: " << mass;
}

double Planet::distance1(const Planet& p) {
	return p.dist;
}

double Planet::diameter1(const Planet& p) {
	return p.diam;
}

void Planet::groupOfPlanets(int size, Planet* p) {
	for (int i = 0; i < size; i++) {
		std::cout << "Data for " << i + 1 << "th planet: ";
		create_planet(p[i]);
		std::cout << std::endl;
	}
}

void Planet::sortPlanets(int size, Planet** p) {
	for (int i = 0; i < size - 1; i++) {
		int k = i;
		double max = distance1(*p[i]);
		double max2 = diameter1(*p[i]);
		for (int j = 0; j < size; j++) {
			double d = distance1(*p[j]);
			double d2 = diameter1(*p[i]);
			if (d > max && d2 > max2) {
				max = d;
				max2 = d2;
				k = j;
			}
		}
		Planet* pl; 
		pl = p[i]; p[i] = p[k]; p[k] = pl;
	}
}

void Planet::show_planets_data(int size, Planet** p) {
	for (int i = 0; i < size; i++) {
		show_planet(*p[i]);
	}
}