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

Pendulum::Pendulum(const std::string& _name, const std::string& _effect,
	unsigned int _rarity, unsigned int _attackPoints, unsigned int _protectPoints, MagicType _type, unsigned int _scale)
	: Card(_name, _effect, _rarity, CardType::pendulum), MonsterCard(_name, _effect, _rarity, _attackPoints, _protectPoints),
	MagicCard(_name, _effect, _rarity, _type)
{
	if (_scale >= 1 && _scale <= 13) {
		this->scale = _scale;
	}
	else {
		std::cerr << "The pendulum scale cannot be below 1 or above 13!\n";
	}
}

unsigned int Pendulum::getScale() const {
	return this->scale;
}

Card* Pendulum::clone() const
{
	return new Pendulum(*this);
}