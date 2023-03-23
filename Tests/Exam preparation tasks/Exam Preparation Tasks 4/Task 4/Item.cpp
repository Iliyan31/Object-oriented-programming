
#include "Item.hpp"

Item::Item(const std::string& name, const std::string& code, const double& price, Type type)
	: name(name), code(code), price(price), type(type)
{
}

std::string Item::getName() const
{
	return this->name;
}

std::string Item::getCode() const
{
	return this->code;
}

double Item::getPrice() const
{
	return this->price;
}

void Item::setName(const std::string& name)
{
	this->name = name;
}

void Item::setCode(const std::string& code)
{
	this->code = code;
}

void Item::setprice(const double& price)
{
	this->price = price;
}
