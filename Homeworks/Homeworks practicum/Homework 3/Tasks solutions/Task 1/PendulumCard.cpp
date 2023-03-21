/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Iliyan Yordanov
* @idnumber 62546
* @task 1
* @compiler VC
*/

#include "PendulumCard.hpp"

Pendulum::Pendulum(std::string name, std::string effect, unsigned int defence, unsigned int attack, Type type, unsigned int _scale)
	: Base(name, effect), Monster(name, effect, defence, attack), Magic(name, effect, type) {

	if (_scale > 13) {
		std::cerr << "It can't be above 13!\n";
	}
	else if (_scale < 1) {
		std::cerr << "It can't be below 1!\n";
	}
	else {
		this->scale = _scale;
	}
}

unsigned int Pendulum::getScale() const {
	return this->scale;
}