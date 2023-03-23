
#include "Base.hpp"

Base::Base(const std::string& colour, const Type& type) : colour(colour), type(type)
{
}

void Base::SetColour(const std::string& colour)
{
	this->colour = colour;
}

std::string Base::getColour() const
{
	return this->colour;
}
