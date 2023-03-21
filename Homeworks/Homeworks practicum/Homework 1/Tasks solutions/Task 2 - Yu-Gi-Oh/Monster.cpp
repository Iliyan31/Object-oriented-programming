
/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Iliyan Yordanov
* @idnumber 62546
* @task 2
* @compiler VC
*/


#include "Duelist.hpp"

Monster::Monster() : attackPoints(0), protectingPoints(0) {
	strcpy_s(name, 2, " ");
}

Monster::Monster(const char* _name, unsigned int at, unsigned int pr) : attackPoints(at), protectingPoints(pr) {
	strcpy_s(name, (strlen(_name) + 1), _name);
}

Monster::Monster(const Monster& m) {
	strcpy_s(name, (strlen(m.name) + 1), m.name);
	attackPoints = m.attackPoints;
	protectingPoints = m.protectingPoints;
}

void Monster::showMonsterCard() const {
	std::cout << "The name of the Monster: " << name << std::endl;
	std::cout << "The attack points of the monster: " << attackPoints << std::endl;
	std::cout << "The protecting points of the monster: " << protectingPoints << std::endl;
}