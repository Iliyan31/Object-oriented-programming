
#include "Fruit.hpp"

Fruit::Fruit(const std::string& _name, const std::string& _colour, double _price, unsigned int _calories)
	: StoreItem(TypeItem::fruit, _price, _calories), name(_name), colour(_colour) {}

std::string Fruit::getName() const
{
	return this->name;
}

std::string Fruit::getColour() const
{
	return this->colour;
}

void Fruit::setName(const std::string& _name)
{
	this->name = _name;
}

void Fruit::setColour(const std::string& _colour)
{
	this->colour = _colour;
}

bool Fruit::operator>(const Fruit& f) const
{
	return this->calories > f.calories;
}

void Fruit::print() const
{
	std::cout << "Name of the product: " << name << "\n";
	std::cout << "Colour of the product: " << colour << "\n";
}

StoreItem* Fruit::clone() const
{
	return new Fruit(*this);
}