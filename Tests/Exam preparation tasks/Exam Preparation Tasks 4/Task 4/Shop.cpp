
#include "Shop.hpp"

Shop::Shop(const Shop& s) {
	this->justCopy(s);
}

Shop& Shop::operator=(const Shop& s) {
	if (this != &s) {
		this->justClear();
		this->justCopy(s);
	}
	return *this;
}

Shop::~Shop()
{
	this->justClear();
}

void Shop::AddItem(Item* item)
{
	this->items.push_back(item->clone());
}

void Shop::RemoveItem(const std::string& code)
{
	for (int i = 0; i < this->items.size(); i++) {
		if (this->items[i]->getCode() == code) {
			delete this->items[i];
			this->items.erase(this->items.begin() + i);
		}
	}
}

void Shop::print(const double& _price) const
{
	for (int i = 0; i < this->items.size(); i++) {
		if (this->items[i]->getPrice() < _price) {
			std::cout << this->items[i]->getName() << "\n";
			std::cout << this->items[i]->getPrice() << "\n";
		}
	}
}

void Shop::searchItem(const std::string& code) const
{
	for (int i = 0; i < this->items.size(); i++) {
		if (this->items[i]->getCode() == code) {
			std::cout << this->items[i]->getName() << "\n";
			std::cout << this->items[i]->getPrice() << "\n";
		}
	}
}

void Shop::justCopy(const Shop& s)
{
	this->items.clear();
	for (int i = 0; i < s.items.size(); i++) {
		this->AddItem(s.items[i]);
	}
}

void Shop::justClear()
{
	for (int i = 0; i < this->items.size(); i++) {
		delete this->items[i];
	}
	this->items.clear();
}
