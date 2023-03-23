
#include "Card.hpp"

Card::Card(const std::string& name, const size_t& size, const size_t& number, Type type)
	: name(name), size(size), number(number), type(type) {}


void Card::setName(const std::string& name) {
	this->name = name;
}

void Card::setSize(const size_t& size) {
	this->size = size;
}

void Card::setNumber(const size_t& number)
{
	this->number = number;
}

std::string Card::getName() const
{
	return this->name;
}

size_t Card::getSize() const
{
	return this->size;
}

size_t Card::getNumber() const
{
	return this->number;
}
