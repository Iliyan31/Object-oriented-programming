
#ifndef DESKTOPPC
#define DESKTOPPC
#include "base.hpp"

class DesktopPC : public Base {
private:
	int power;
public:
	DesktopPC(double _processor = 0, unsigned int _HDD = 0, int _price = 0, int _power = 0);
	double getPriceInEuro() const;
	Type getType() const;
};

#endif // !DESKTOPPC
