
#include "Hero.hpp"

Hero::Hero(const std::string& name, const size_t& size, const size_t& number, const size_t attack, const size_t protect)
	: Card (name, size, number, Type::hero), attack(attack), protect(protect)
{
}

void Hero::setAttack(const size_t& attack)
{
	this->attack = attack;
}

void Hero::setProtect(const size_t& protect)
{
	this->protect = protect;
}

size_t Hero::getAttack() const
{
	return this->attack;
}

size_t Hero::getProtect() const
{
	return this->protect;
}

Card* Hero::clone() const{
	return new Hero(*this);
}

void Hero::printCards() const
{
	std::cout << this->getName() << " " << this->getSize() << " " << this->getNumber() << " " << this->attack << " " << this->protect << "\n";
}