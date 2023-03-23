
#include "Shop.hpp"

Shop::Shop(const Shop& s) {
	this->justCopy(s);
}

Shop& Shop::operator=(const Shop& s) {
	if (this != &s) {
		this->justCopy(s);
		this->justClear();
	}
	return *this;
}

Shop::~Shop() {
	this->justClear();
}

void Shop::AddItem(StoreItem* s) {
	this->shop.push_back(s->clone());
}

void Shop::removeItem(const int& index) {
	if (index < this->shop.size()) {
		this->shop.erase(this->shop.begin() + index);
	}
}

void Shop::changePrice(const int& index, const double& price) {
	if (index < this->shop.size()) {
		this->shop.at(index)->setPrice(price);
	}
}

void Shop::changeName(const int& index, const std::string& name) {
	if (index < this->shop.size()) {
		this->shop.at(index)->setName(name);
	}
}

void Shop::print() const {
	for (int i = 0; i < shop.size(); i++) {
		Fruit* fruit = dynamic_cast<Fruit*>(this->shop[i]);
		Vegetable* veg = dynamic_cast<Vegetable*>(this->shop[i]);
		if (fruit) {
			std::cout << "Fruit :"<<fruit->getName()<<" "<<fruit->getPrice()<<" "<<fruit->getCalories()<<" "<<fruit->getColour()<<"\n";
		}
		if (veg) {
			std::cout<<"Vegetable: "<< veg->getName() << " " << veg->getPrice() << " " << veg->getCalories() << " " << veg->getSort() << "\n";
		}
	}
}

void Shop::hasMostCalories() const {
	int tempi = 0;
	int max = 0;
	for (int i = 0; i < shop.size(); i++) {
		Fruit* fruit = dynamic_cast<Fruit*>(this->shop[i]);
		if (fruit) {
			if (max == 0) {
				max = fruit->getCalories();
				tempi = i;
			}
			if (max < fruit->getCalories()) {
				max = fruit->getCalories();
				tempi = i;
			}
		}
	}
	for (int i = 0; i < shop.size(); i++) {
		Fruit* fruit = dynamic_cast<Fruit*>(this->shop[i]);
		if (fruit && tempi==i) {
			std::cout << "Fruit :" << fruit->getName() << " " << fruit->getPrice() << " " << fruit->getCalories() << " " << fruit->getColour() << "\n";
		}
	}
}

void Shop::justCopy(const Shop& s) {
	this->shop.clear();
	for (int i = 0; i < s.shop.size(); i++) {
		this->AddItem(s.shop[i]);
	}
}

void Shop::justClear() {
	for (int i = 0; i < shop.size(); i++) {
		delete[] this->shop[i];
	}
	this->shop.clear();
}
