
#include "drink.hpp"

const int SIZE_NAME = 50;

Drink::Drink(const char* init_name, const int init_calories, const double& init_quantity, const double& init_price) {
	delete[] name;
	if (init_name == nullptr) {
		this->name = new char[1];
		this->name[0] = '\0';
	}
	else {
		this->name = new char[strlen(init_name) + 1];
		strcpy_s(this->name, strlen(init_name) + 1, init_name);
	}
	
	this->calories = init_calories;
	this->quantity = init_quantity;
	this->price = init_price;
}

Drink::Drink(const Drink& other) : calories(other.calories), quantity(other.quantity), price(other.price){

	if (other.name == nullptr) {
		this->name = new char[1];
		this->name[0] = '\0';
	}
	else {
		this->name = new char[strlen(other.name) + 1];
		strcpy_s(this->name, strlen(other.name) + 1, other.name);
	}
}

Drink& Drink::operator=(const Drink& other){
	if (this != &other) {
		delete[] name;
		this->name = new char[strlen(other.name) + 1];
		strcpy_s(this->name, strlen(other.name) + 1, other.name);
		this->calories = other.calories;
		this->quantity = other.quantity;
		this->price = other.price;
	}
	return *this;
}

const char* Drink::get_name() const {
	return this->name;
}

int Drink::get_calories() const {
	return this->calories;
}

double Drink::get_quantity() const {
	return this->quantity;
}

double Drink::get_price() const {
	return this->price;
}

void Drink::set_name(const char* new_name){
	delete[] name;
	this->name = new char[strlen(new_name) + 1];
	strcpy_s(name, strlen(new_name) + 1, new_name);
}

Drink::Drink() : calories(0), quantity(0), price(0) {
	this->name = new char[1];
	this->name[0] = '\0';
}

Drink::~Drink() {
	delete[] name;
}

void Drink::set_calories(int _calories) {
	this->calories = _calories;
}

void Drink::set_quantity(double _quantity) {
	this->quantity = _quantity;
}

void Drink::set_price(double _price) {
	this->price = _price;
}

void Drink::create_drink() {
	delete[] name;
	name = new char[SIZE_NAME];
	printf("Please insert the name of the drink: ");
	std::cin >> name;
	printf("Please insert the calories of the drink: ");
	std::cin >> calories;
	printf("Please insert the quantity of the drink: ");
	std::cin >> quantity;
	printf("Please insert the price of the drink: ");
	std::cin >> price;
}

void Drink::print() const {
	std::cout << "Name of the drink: " << name;
	std::cout << "Calories int the drink: " << calories;
	std::cout << "Quantity of the drink: " << quantity;
	std::cout << "Price of the drink: " << price;
	std::cout << std::endl;
}