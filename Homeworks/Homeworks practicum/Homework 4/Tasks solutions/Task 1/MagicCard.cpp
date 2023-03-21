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

#include "MagicCard.hpp"

MagicCard::MagicCard(const std::string& _name, const std::string& _effect, unsigned int _rarity, MagicType _type) 
	: Card(_name, _effect, _rarity, CardType::Magic), magType(_type) {}

MagicType MagicCard::getMagicType() const
{
	return this->magType;
}

Card* MagicCard::clone() const
{
	return new MagicCard(*this);
}