#pragma once
#include "Item.hpp"

class Drink : public Item {
public:
	Drink(const std::string& name = " ", const std::string& code = " ", const double& price = 0, const double& alcoholPercents = 0);
	double getAlcoholPercents() const;
	void setAlcoholPercents(const double& alcoholPercents);
	Item* clone() const;
	~Drink() = default;
private:
	double alcoholPercents;
};
