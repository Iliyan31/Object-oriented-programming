#pragma once
#include "Item.hpp"

class Eat : public Item {
public:
	Eat(const std::string& name = " ", const std::string& code = " ", const double& price = 0, const size_t& calories = 0);
	size_t getCalories() const;
	void setCalories(const size_t& calories);
	Item* clone() const;
	~Eat() = default;

private:
	size_t calories;
};