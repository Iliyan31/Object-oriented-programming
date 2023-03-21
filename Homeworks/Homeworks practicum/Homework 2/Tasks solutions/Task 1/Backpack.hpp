
/**
* Solution to homework assignment 2
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021 *
* @author Iliyan Yordanov
* @idnumber 62546
* @task 1
* @compiler VC
*/

#ifndef BACKPACK
#define BACKPACK

#include <iostream>
#include <cstring>
#include <vector>
#include <utility>

#include "materials.hpp"
#include "money.hpp"


template <typename B>
class Backpack {
private:

	B backpack;
	unsigned int slots;

public:
	Backpack();
	Backpack(B _backpack);
	Backpack(const Backpack& b);
	~Backpack() = default;

	bool isEmpty() const;
	bool isFull() const;
	void setEmpty();
	void addItem(B item);
	void removeItem(B item);
	int getBackpackSlots() const;
	void print() const;

	friend std::ostream& operator<<(std::ostream& out, const Backpack& in);
};


Backpack<Money>::Backpack() : slots(0) {
	backpack = Money();
}

Backpack<Materials>::Backpack() : slots(0) {
	backpack = Materials();
}

Backpack<Money>::Backpack(Money _backpack) {
	backpack = _backpack;
}

Backpack<Materials>::Backpack(Materials _backpack) {
	if (_backpack.getsSlots() <= 16) {
		this->slots += _backpack.getsSlots();
		backpack = _backpack;
	}
	else {
		printf("You can't add more items!");
	}
}

Backpack<Money>::Backpack(const Backpack& b) {
	backpack = b.backpack;
}

Backpack<Materials>::Backpack(const Backpack& b) {
	if (b.backpack.getsSlots() <= 16) {
		this->slots += b.backpack.getsSlots();
		backpack = b.backpack;
	}
	else {
		printf("You can't add more items!");
	}
}

template<typename B>
bool Backpack<B>::isEmpty() const {
	return this->slots == 0;
}

template<typename B>
bool Backpack<B>::isFull() const {
	return this->slots == 16;
}

template<class B>
void Backpack<B>::setEmpty() {
	backpack.setEmpty();
	this->slots = 0;
}

void Backpack<Materials>::addItem(Materials item) {
	if (slots < 16) {
		if (item.getsSlots() <= 16) {
			this->slots += item.getsSlots();
			backpack += item;
		}
	}
	else {
		printf("You can't add more items!");
	}
}

void Backpack<Money>::addItem(Money item) {
	backpack += item;
}

void Backpack<Money>::removeItem(Money item) {
	backpack -= item;
}

void Backpack<Materials>::removeItem(Materials item) {
	if (isEmpty()) {
		printf("There is nothing to remove!\n");
	}
	else {
		this->slots -= item.getsSlots();
		backpack -= item;
	}
}

template<typename B>
int Backpack<B>::getBackpackSlots() const {
	return this->slots;
}


void Backpack<Money>::print() const {
	backpack.printMoney();
}

void Backpack<Materials>::print() const {
	backpack.printMater();
}


std::ostream& operator<<(std::ostream& out, const Backpack<Materials>& in) {
	out << in.backpack << " " << in.slots << " ";
	return out;
}

std::ostream& operator<<(std::ostream& out, const Backpack<Money>& in) {
	out << in.backpack << " " <<in.slots <<" ";
	return out;
}

#endif // !BACKPACK