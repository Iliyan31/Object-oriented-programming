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

#include "MagicCard.hpp"
#include "MonsterCard.hpp"

class Pendulum : public MonsterCard, public MagicCard {
private:
	unsigned int scale;
public:
	Pendulum(const std::string& _name = " ", const std::string& _effect = " ", unsigned int _rarity = 0,
		unsigned int _attackPoints = 0, unsigned int _protectPoints = 0, MagicType _type = MagicType::None, unsigned int _scale = 1); 

	unsigned int getScale() const;

	Card* clone() const;

	~Pendulum() = default;
};

#endif // !PENDULUMCARD