
#include "StoreItem.hpp"

StoreItem::StoreItem(TypeItem _type, double _price, unsigned int _calories) 
	: type(_type), calories(_calories) {
	if (_price >= 0) {
		this->price = _price;
	}
	else {
		std::cerr << "Invalid price!\n";
	}
}

TypeItem StoreItem::getItemType() const {
	return this->type;
}

double StoreItem::getPrice() const {
	return this->price;
}

unsigned int StoreItem::getCalories() const
{
	return this->calories;
}

void StoreItem::setItemType(const TypeItem& _type)
{
	this->type = _type;
}

void StoreItem::setPrice(const double& _price)
{
	this->price = _price;
}

void StoreItem::setCalories(const unsigned int& _calories)
{
	this->calories = _calories;
}

void StoreItem::print() const
{
	std::cout << "Price: " << this->price<< "\n";
	std::cout << "Calories: " << this->calories << "\n";
	std::cout << "Type of the product: ";
	switch (type) {
	case TypeItem::fruit: printf("Fruit\n"); break;
	case TypeItem::vegetable: printf("Vegetable\n"); break;
	default: printf("It was not inserted!\n");
	}
}

