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

#ifndef MONSTERCARD
#define MONSTERCARD

#include "Card.hpp"

class MonsterCard : virtual public Card {
protected:
	unsigned int attackPoints;
	unsigned int protectPoints;
public:
	MonsterCard(const std::string& _name = " ", const std::string& _effect = " ", unsigned int _rarity = 0,
		unsigned int _attackPoints = 0, unsigned int _protectPoints = 0);
	unsigned int getAttackPoints() const;
	unsigned int getProtectPoints() const;

	Card* clone() const;

	~MonsterCard() = default;
};

#endif // !MONSTERCARD