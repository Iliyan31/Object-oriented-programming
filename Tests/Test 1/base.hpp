
#ifndef BASE
#define BASE
#include <iostream>

#define M 0.5113

enum class Type {
	None, 
	laptop,
	desktopPC
};

class Base {
protected:
	Type type;
	double processor;
	unsigned int HDD;
	int price;
public:
	Base(double processor = 0, unsigned int HDD = 0, int price = 0, Type type = Type::None);
	virtual double getPriceInEuro() const = 0;
	virtual Type getType() const = 0;
};

#endif // !BASE
