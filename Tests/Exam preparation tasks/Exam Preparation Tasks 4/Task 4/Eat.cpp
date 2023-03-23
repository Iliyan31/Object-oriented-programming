
#include "Eat.hpp"

Eat::Eat(const std::string& name, const std::string& code, const double& price, const size_t& calories)
	: Item(name, code, price, Type::eat), calories(calories)
{
}

size_t Eat::getCalories() const
{
	return this->calories;
}

void Eat::setCalories(const size_t& calories)
{
	this->calories = calories;
}

Item* Eat::clone() const
{
	return new Eat(*this);
}
