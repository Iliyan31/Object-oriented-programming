#pragma once
#include "StoreItem.hpp"

class Fruit : public StoreItem {
public:
	Fruit(const std::string& name = " ", const double& price = 0, const size_t& calories = 0, const std::string& colour = " ");

	std::string getColour() const;
	void setColour(const std::string& colour);

	bool operator>(const Fruit& f) const;
	StoreItem* clone() const;
	~Fruit() = default;
private:
	std::string colour;
};