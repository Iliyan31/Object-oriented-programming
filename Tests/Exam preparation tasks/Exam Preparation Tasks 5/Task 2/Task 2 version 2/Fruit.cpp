
#include "Fruit.hpp"

Fruit::Fruit(const std::string& name, const double& price, const size_t& calories, const std::string& colour)
	: StoreItem(name, price, calories, Type::fruit), colour(colour) {}

std::string Fruit::getColour() const
{
	return this->colour;
}

void Fruit::setColour(const std::string& colour)
{
	this->colour = colour;
}

bool Fruit::operator>(const Fruit& f) const {
	return this->getCalories() > f.getCalories();
}

StoreItem* Fruit::clone() const
{
	return new Fruit(*this);
}
