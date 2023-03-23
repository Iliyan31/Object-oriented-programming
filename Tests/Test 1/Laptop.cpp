
#include "Laptop.hpp"

Laptop::Laptop(bool available, unsigned int HDD, int processor, double price)
	: Base(processor, HDD, price, Type::laptop), available(available) {
}

double Laptop::getPriceInEuro() const
{
	return this->price * M;
}

Type Laptop::getType() const
{
	return this->type;
}


