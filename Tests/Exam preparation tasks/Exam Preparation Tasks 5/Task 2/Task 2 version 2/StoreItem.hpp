#pragma once
#include <iostream>
#include <string>

enum class Type {
	fruit,
	vegetable,
	none
};

class StoreItem {
public:
	StoreItem(const std::string& name = " ", const double& price = 0, const size_t& calories = 0, const Type& type = Type::none);

	Type getType() const;
	std::string getName() const;
	double getPrice() const;
	size_t getCalories() const;

	void setType(const Type& type);
	void setName(const std::string& name);
	void setPrice(const double& price);
	void setCalories(const size_t& calories);

	virtual StoreItem* clone() const = 0;
	virtual ~StoreItem() = default;
private:
	Type type;
	std::string name;
	double price;
	size_t calories;
};