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

#ifndef PENDULUMCARD
#define PENDULUMCARD
#include "monsterCard.hpp"
#include "magicCard.hpp"

class Pendulum : public Monster, public Magic {
protected:
	unsigned int scale;
public:
	Pendulum(std::string name = " ", std::string effect = " ", unsigned int defence = 0, unsigned int attack = 0, Type type = Type::none, unsigned int _scale = 0);
	unsigned int getScale() const;
};

#endif // !PENDULUMCARD