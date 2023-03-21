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

#ifndef CARD
#define CARD

#include <iostream>
#include <string>

enum class CardType {
	None,
	Monster,
	Magic,
	pendulum
};

class Card {
protected:
	CardType type;
	std::string name;
	std::string effect;
	unsigned int rarity;
public:
	Card(const std::string& _name = " ", const std::string& _effect = " ", unsigned int _rarity = 0, CardType _type = CardType::None);
	std::string getName() const;
	std::string getEffect() const;
	unsigned int getRarity() const;
	CardType getCardType() const;
	virtual bool operator<(const Card& c) const;
	virtual bool operator>(const Card& c) const;

	virtual Card* clone() const = 0;

	virtual ~Card() = default;
};

#endif // !CARD