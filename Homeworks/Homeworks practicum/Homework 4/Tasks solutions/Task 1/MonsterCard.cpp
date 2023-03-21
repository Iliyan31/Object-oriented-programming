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

#include "MonsterCard.hpp"

MonsterCard::MonsterCard(const std::string& _name, const std::string& _effect, unsigned int _rarity, unsigned int _attackPoints, unsigned int _protectPoints)
	: Card(_name, _effect, _rarity, CardType::Monster), attackPoints(_attackPoints), protectPoints(_protectPoints) {}

unsigned int MonsterCard::getAttackPoints() const {
	return this->attackPoints;
}

unsigned int MonsterCard::getProtectPoints() const {
	return this->protectPoints;
}

Card* MonsterCard::clone() const {
	return new MonsterCard(*this);
}