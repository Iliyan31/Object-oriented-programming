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

#ifndef MONSTER
#define MONSTER

#include "baseClass.hpp"

class Monster : virtual public Base {
protected:
	unsigned int defence;
	unsigned int attack;
public:
	Monster(std::string name = " ", std::string effect = " " , unsigned int _deffence = 0, unsigned int _attack = 0);
	unsigned int getDefence() const;
	unsigned int getAttack() const;
};

#endif // ! MONSTER