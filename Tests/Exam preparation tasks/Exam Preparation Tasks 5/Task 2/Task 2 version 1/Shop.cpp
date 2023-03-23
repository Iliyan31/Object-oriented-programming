
#include "Shop.hpp"

Shop::Shop(const Shop& s)
{
	for (auto shop : s.shop) {
		
	}
}

void Shop::addItem(StoreItem* storeItem)
{
	this->shop.push_back(storeItem->clone());
}
