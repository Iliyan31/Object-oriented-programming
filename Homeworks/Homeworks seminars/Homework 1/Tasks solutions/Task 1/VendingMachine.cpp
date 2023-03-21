
#include "VendingMachine.hpp"

VendingMachine::VendingMachine() : _price(0.0), numberDrinks(0) {
	this->drink = new Drink[1];
	this->drink[0] = Drink();
}

VendingMachine::VendingMachine(const VendingMachine& from) :_price(from._price), numberDrinks(from.numberDrinks) {
	
	this->drink = new Drink[numberDrinks];
	for (int i = 0; i < numberDrinks; i++) {
		drink[i] = from.drink[i];
	}
}

VendingMachine& VendingMachine::operator=(const VendingMachine& from) {
	if (this != &from) {
		delete[] drink;
		this->numberDrinks = from.numberDrinks;
		this->drink = new Drink[numberDrinks];
		for (int i = 0; i < numberDrinks; i++) {
			drink[i] = from.drink[i];
		}
		this->_price = from._price;
	}
	return *this;
}

bool VendingMachine::add_drink(const Drink& to_add){

	for (int i = 0; i < numberDrinks; i++) {
		if (!strcmp(drink[i].get_name(), to_add.get_name())) {
			return false;
		}
	}

	Drink* temp = new Drink[numberDrinks+1];
	for (int i = 0; i < numberDrinks; i++) {
		temp[i] = drink[i];
	}

	delete[] drink;
	drink = new Drink[numberDrinks + 1];

	for (int i = 0; i < numberDrinks; i++) {
		drink[i] = temp[i];
	}

	drink[numberDrinks] = to_add;
	this->numberDrinks++;

	delete[] temp;

	return true;
}

int VendingMachine::buy_drink(const char* drink_name, const double money) {
	
	for (int i = 0; i < numberDrinks; i++) {
		if (!strcmp(drink_name, drink[i].get_name())) {

			if (money >= drink[i].get_price()) {
				this->drink[i] = Drink();
				if (i == numberDrinks - 1) {
					numberDrinks--;
					this->_price += money;
					return 0;
				}
				else {
					for (int j = i; j < numberDrinks; j++) {
						if (j = numberDrinks - 1) {
							break;
						}
						this->drink[j] = drink[j + 1];
					}
					numberDrinks--;
					this->_price += money;
					return 0;
				}
			}
			else if (money < drink[i].get_price()) {
				this->_price += money;
				return 1;
			}
		}
	}
	return 2;
}

double VendingMachine::get_income() const {
	return this->_price;
}

VendingMachine::~VendingMachine() {
	delete[] drink;
}