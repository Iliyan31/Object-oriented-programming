
#ifndef FRUIT
#define FRUIT
#include "StoreItem.hpp"

class Fruit : public StoreItem {
protected:
	std::string name;
	std::string colour;
public:
	Fruit(const std::string& _name = " ", const std::string& _colour = " ", double _price = 0, unsigned int _calories = 0);
	virtual std::string getName() const;
	std::string getColour() const;
	void setName(const std::string& _name);
	void setColour(const std::string& _colour);
	bool operator>(const Fruit& f) const;
	virtual void print() const;
	StoreItem* clone() const;
	~Fruit() = default;
};

#endif // !FRUIT
