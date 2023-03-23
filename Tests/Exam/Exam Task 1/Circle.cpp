
#include "Circle.hpp"

Circle::Circle(const std::string& colour, const size_t& radius)
	: Base(colour, Type::circle), radius(radius)
{
}

size_t Circle::getradius() const
{
	return this->radius;
}

void Circle::setRadius(const size_t& radius)
{
	this->radius = radius;
}

Base* Circle::clone() const {
	return new Circle(*this);
}

double Circle::getSeize() const {
	return 2 * (PI * (this->radius * this->radius));
}

