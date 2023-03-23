#pragma once
#include "Drink.hpp"
#include "Eat.hpp"
#include <vector>

class Shop {
public:
	Shop() = default;
	Shop(const Shop& s);
	Shop& operator=(const Shop& s);
	~Shop();

	void AddItem(Item* item);
	void RemoveItem(const std::string& code);
	void print(const double& _price) const;
	void searchItem(const std::string& code) const;

private:
	void justCopy(const Shop& s);
	void justClear();
	std::vector<Item*> items;
};