
#ifndef SHOP
#define SHOP
#include <vector>

#include "Fruit.hpp"
#include "Vegetable.hpp"

class Shop {
private:
	std::vector<StoreItem*> shop;
public:
	Shop(const Shop& s);
	void addItem(StoreItem* storeItem);
};

#endif // !SHOP
