
#include "StoreItem.hpp"

StoreItem::StoreItem(const std::string& name, const double& price, const size_t& calories, const Type& type)
	: name(name), price(price), calories(calories), type(type) {}

Type StoreItem::getType() const
{
	return this->type;
}

std::string StoreItem::getName() const
{
	return this->name;
}

double StoreItem::getPrice() const
{
	return this->price;
}

size_t StoreItem::getCalories() const
{
	return this->calories;
}


void StoreItem::setType(const Type& type)
{
	this->type = type;
}

void StoreItem::setName(const std::string& name)
{
	this->name = name;
}

void StoreItem::setPrice(const double& price)
{
	this->price = price;

}

void StoreItem::setCalories(const size_t& calories)
{
	this->calories = calories;
}
