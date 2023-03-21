
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

#ifndef INVENTORY
#define INVENTORY

#include <iostream>
#include <cstring>
#include <vector>
#include <utility>

#include "Backpack.hpp"
#include "Equipement.hpp"

template<typename I>
class Inventory {
private:
	I inventory;
public:

	Inventory();
	Inventory(I _inventory);
	Inventory(const Inventory& in);
	~Inventory() = default;

	friend std::ostream& operator<<(std::ostream& out, const Inventory& in);
	bool operator==(const Inventory& in) const;
	bool operator!=(const Inventory& in) const;
};


Inventory<Backpack<Money>>::Inventory(){
	Backpack<Money> temp = Backpack<Money>();
	inventory = temp;
}

Inventory<Backpack<Materials>>::Inventory() {
	Backpack<Materials> temp = Backpack<Materials>();
	inventory = temp;
}

Inventory<Equipment<Armor>>::Inventory() {
	Equipment<Armor> temp = Equipment<Armor>();
	inventory = temp;
}

Inventory<Equipment<Weapon>>::Inventory() {
	Equipment<Weapon> temp = Equipment<Weapon>();
	inventory = temp;
}




Inventory<Equipment<Armor>>::Inventory(Equipment<Armor> _inventory) {
	inventory = _inventory;
}
Inventory<Equipment<Weapon>>::Inventory(Equipment<Weapon> _inventory) {
	inventory = _inventory;
}
Inventory<Backpack<Materials>>::Inventory(Backpack<Materials> _inventory) {
	inventory = _inventory;
}
Inventory<Backpack<Money>>::Inventory(Backpack<Money> _inventory) {
	inventory = _inventory;
}





Inventory<Backpack<Money>>::Inventory(const Inventory& in) {
	inventory = in.inventory;
}
Inventory<Backpack<Materials>>::Inventory(const Inventory& in) {
	inventory = in.inventory;
}
Inventory<Equipment<Weapon>>::Inventory(const Inventory& in) {
	inventory = in.inventory;
}
Inventory<Equipment<Armor>>::Inventory(const Inventory& in) {
	inventory = in.inventory;
}



std::ostream& operator<<(std::ostream& out, const Inventory<Backpack<Materials>>& in) {
	out << in.inventory;
	return out;
}

std::ostream& operator<<(std::ostream& out, const Inventory<Backpack<Money>>& in) {
	out << in.inventory;
	return out;
}

std::ostream& operator<<(std::ostream& out, const Inventory<Equipment<Armor>>& in) {
	out << in.inventory;
	return out;
}

std::ostream& operator<<(std::ostream& out, const Inventory<Equipment<Weapon>>& in) {
	out << in.inventory;
	return out;
}


bool Inventory<Equipment<Armor>>::operator==(const Inventory& in) const {
	return inventory.slotsTaken() == in.inventory.slotsTaken();
}
bool Inventory<Equipment<Weapon>>::operator==(const Inventory& in) const {
	return inventory.slotsTaken() == in.inventory.slotsTaken();
}
bool Inventory<Backpack<Materials>>::operator==(const Inventory& in) const {
	return inventory.getBackpackSlots()== in.inventory.getBackpackSlots();
}
bool Inventory<Backpack<Money>>::operator==(const Inventory& in) const {
	return inventory.getBackpackSlots() == in.inventory.getBackpackSlots();
}



bool Inventory<Equipment<Armor>>::operator!=(const Inventory& in) const {
	return inventory.slotsTaken() != in.inventory.slotsTaken();
}
bool Inventory<Equipment<Weapon>>::operator!=(const Inventory& in) const {
	return inventory.slotsTaken() != in.inventory.slotsTaken();
}
bool Inventory<Backpack<Materials>>::operator!=(const Inventory& in) const {
	return inventory.getBackpackSlots() != in.inventory.getBackpackSlots();
}
bool Inventory<Backpack<Money>>::operator!=(const Inventory& in) const {
	return inventory.getBackpackSlots() != in.inventory.getBackpackSlots();
}


#endif // INVENTORY!