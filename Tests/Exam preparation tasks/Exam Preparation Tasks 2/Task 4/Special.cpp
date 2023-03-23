
#include "Special.hpp"

Special::Special(const std::string& name, const size_t& size, const size_t& number, const size_t attack, const size_t protect, const std::string& effect, const size_t& level)
	: Magic(name, size, number, effect), Hero(name, size, number, attack, protect), Card(name, size, number, Type::special), level(level) {}


void Special::setLevel(const size_t& level)
{
	this->level = level;
}

size_t Special::getLevel() const
{
	return this->level;
}

Card* Special::clone() const {
	return new Special(*this);
}

void Special::printCards() const
{
	std::cout << this->getName() << " " << this->getSize() << " " << this->getNumber() << " " <<
		this->getAttack() << " " << this->getProtect() << " " << this->getEffect() << " " << this->level << "\n";
}
