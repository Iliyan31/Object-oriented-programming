#pragma once

#include <iostream>

const int MAX_size = 20;

class Planet {
private:
	char name[MAX_size];
	double dist;
	double diam;
	double mass;
public:
	void create_planet(Planet& p);
	void show_planet(const Planet& p);
	double distance1(const Planet& p);
	double diameter1(const Planet& p);
	void groupOfPlanets(int size, Planet* p);
	void sortPlanets(int size, Planet** p);
	void show_planets_data(int size, Planet** p);
};