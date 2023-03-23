
#include "Vegetable.hpp"

Vegetable::Vegetable(const std::string& _name, const std::string& _sort) 
	: StoreItem(TypeItem::vegetable), name(_name), sort(_sort) {}

std::string Vegetable::getName() const
{
	return this->name;
}

std::string Vegetable::getSort() const
{
	return this->sort;
}

bool Vegetable::operator==(const Vegetable& v)
{
	return this->sort == v.sort;
}
