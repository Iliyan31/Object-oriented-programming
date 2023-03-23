
#ifndef LAPTOP
#define LAPTOP
#include "base.hpp"
class Laptop : public Base {
private:
	bool available;
public:
	Laptop(bool available, unsigned int HDD, int processor, double price);
	double getPriceInEuro() const;
	Type getType() const;
};

#endif // !LAPTOP
