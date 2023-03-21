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

#ifndef MAGICCARD
#define MAGICCARD
#include "Card.hpp"

enum class MagicType {
	None,
	trap,
	buff,
	spell
};

class MagicCard : virtual public Card{
protected:
	MagicType magType;
public:
	MagicCard(const std::string& _name = " ", const std::string& _effect = " ", unsigned int _rarity = 0, MagicType _type = MagicType::None);
	MagicType getMagicType() const;

	Card* clone() const;

	~MagicCard() = default;
};

#endif // !MAGICCARD