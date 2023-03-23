
#include "DesktopPC.hpp"

DesktopPC::DesktopPC(double _processor, unsigned int _HDD, int _price, int _power)
	: Base(_processor, _HDD, _price, Type::desktopPC), power(_power)
{
}

double DesktopPC::getPriceInEuro() const
{
	return this->price * M;
}

Type DesktopPC::getType() const
{
	return this->type;
}
