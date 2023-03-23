#pragma once
#include "Fruit.hpp"
#include "Vegetable.hpp"
#include <vector>

class Shop {
public:
	Shop() = default;
	Shop(const Shop& s);
	Shop& operator=(const Shop& s);
	~Shop();

	void AddItem(StoreItem* s);
	void removeItem(const int& index);

	void changePrice(const int& index, const double& price);
	void changeName(const int& index, const std::string& name);
	void print() const;
	void hasMostCalories() const;
private:
	void justCopy(const Shop& s);
	void justClear();
	std::vector<StoreItem*> shop;
};