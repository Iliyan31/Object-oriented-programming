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

#include "monsterCard.hpp"

Monster::Monster(std::string name, std::string effect, unsigned int _defence, unsigned int _attack) 
	: Base(name, effect), defence(_defence), attack(_attack){}

unsigned int Monster::getDefence() const {
	return this->defence;
}

unsigned int Monster::getAttack() const {
	return this->attack;
}