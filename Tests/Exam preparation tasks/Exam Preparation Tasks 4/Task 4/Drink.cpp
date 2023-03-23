
#include "Drink.hpp"

Drink::Drink(const std::string& name, const std::string& code, const double& price, const double& alcoholPercents)
	: Item(name, code, price, Type::drink), alcoholPercents(alcoholPercents) {
}

double Drink::getAlcoholPercents() const
{
	return this->alcoholPercents;
}

void Drink::setAlcoholPercents(const double& alcoholPercents)
{
	this->alcoholPercents = alcoholPercents;
}

Item* Drink::clone() const
{
	return new Drink(*this);
}
