
#include "Magic.hpp"


Magic::Magic(const std::string& name, const size_t& size, const size_t& number, const std::string& effect)
	: Card(name, size, number, Type::magic), effect(effect) {}


std::string Magic::getEffect() const {
	return this->effect;
}

void Magic::setEffect(const std::string& name) {
	this->effect = effect;
}

Card* Magic::clone() const {
	return new Magic(*this);
}

void Magic::printCards() const {
	std::cout << this->getName() << " " << this->getSize() << " " << this->getNumber() << " " << this->effect << "\n";
}
