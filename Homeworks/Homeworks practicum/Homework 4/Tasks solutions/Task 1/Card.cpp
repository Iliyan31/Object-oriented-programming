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

#include "Card.hpp"

Card::Card(const std::string& _name, const std::string& _effect, unsigned int _rarity, CardType _type)
	: name(_name), effect(_effect), rarity(_rarity), type(_type) {}

std::string Card::getName() const {
	return this->name;
}

std::string Card::getEffect() const {
	return this->effect;
}

unsigned int Card::getRarity() const {
	return this->rarity;
}

CardType Card::getCardType() const {
	return this->type;
}

bool Card::operator<(const Card& c) const {		
	return this->rarity < c.rarity;
}

bool Card::operator>(const Card& c) const {	
	return this->rarity > c.rarity;
}