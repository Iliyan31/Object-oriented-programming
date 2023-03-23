
#ifndef HERO
#define HERO
#include "Card.hpp"

class Hero : virtual public Card {
public:
	Hero(const std::string& name = " ", const size_t& size = 0, 
		const size_t& number = 0, const size_t attack = 0, const size_t protect = 0);

	void setAttack(const size_t& attack);
	void setProtect(const size_t& protect);

	size_t getAttack() const;
	size_t getProtect() const;

	Card* clone() const;
	void printCards() const;
	~Hero() = default;
private:
	size_t attack;
	size_t protect;
};

#endif // !HERO