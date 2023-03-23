
#include "Rectangle.hpp"

Rectangle::Rectangle(const std::string& colour, const size_t& lenght, const size_t& width)
	: Base(colour, Type::rectangle), lenght(lenght), width(width)
{
}

void Rectangle::setWidth(const size_t& width)
{
	this->width = width;
}

void Rectangle::setLenght(const size_t& lenght)
{
	this->lenght = lenght;
}

size_t Rectangle::getLenght() const
{
	return this->lenght;
}

size_t Rectangle::getWidth() const
{
	return this->width;
}

Base* Rectangle::clone() const
{
	return new Rectangle(*this);
}

double Rectangle::getSeize() const {
	return (this->lenght * this->width);
}
