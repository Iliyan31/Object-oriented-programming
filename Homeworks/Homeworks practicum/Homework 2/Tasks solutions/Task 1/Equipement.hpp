
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

#ifndef EQUIPEMENT
#define EQUIPEMENT

#include <iostream>
#include <cstring>
#include <vector>
#include <utility>

#include "weapons.hpp"
#include "armor.hpp"


template <typename E>
class Equipment {
private:

	std::vector<E> equipement;
	unsigned int slots;

public:
	Equipment();
	Equipment(std::vector<E> items);
	Equipment(const Equipment& e);
	~Equipment() = default;

	int slotsTaken() const;
	bool isEmpty() const;
	bool isFull() const;
	void removeItem(E item);
	void addItem(E item);
	void setEmpty();
	E bestItem() const;
	int getEquipementSlots() const;

	bool operator==(const Equipment& e) const;
	bool operator!=(const Equipment& e) const;
	Equipment& operator=(const Equipment& e);

	void print() const;
	friend std::ostream& operator<<(std::ostream& out, const Equipment& in);
};

template<typename E>
Equipment<E>::Equipment() : slots(0) {
	E temp;
	equipement.push_back(temp);
}

Equipment<Weapon>::Equipment(std::vector<Weapon> items) {
	for (int i = 0; i < items.size(); i++) {
		if (i >= 24) break;
		if (slots < 24) {
			if (items[i].getWeaponType() == 1) {
				slots++;
				equipement.push_back(items[i]);
			}
			else if (items[i].getWeaponType() == 2) {
				if (slots + 2 <= 24) {
					slots += 2;
					equipement.push_back(items[i]);
				}
				else {
					printf("You can't add more items!");
				}
			}
		}
		else {
			printf("You can't add more items!");
		}
	}
}

Equipment<Armor>::Equipment(std::vector<Armor> items) {
	for (int i = 0; i < items.size(); i++) {
		if (i >= 24) break;
		if (slots < 24) {
			slots++;
			equipement.push_back(items[i]);
		}
		else {
			printf("You can't add more items!");
		}
	}
}

Equipment<Armor>::Equipment(const Equipment& e) {
	for (int i = 0; i < e.equipement.size(); i++) {
		if (i >= 24) break;
		if (slots < 24) {
			slots++;
			equipement.push_back(e.equipement[i]);
		}
		else {
			printf("You can't add more items!");
		}
	}
}

Equipment<Weapon>::Equipment(const Equipment& e) {
	for (int i = 0; i < e.equipement.size(); i++) {
		if (i >= 24) break;
		if (slots < 24) {
			if (e.equipement[i].getWeaponType() == 1) {
				slots++;
				equipement.push_back(e.equipement[i]);
			}
			else if (e.equipement[i].getWeaponType() == 2) {
				if (slots + 2 <= 24) {
					slots += 2;
					equipement.push_back(e.equipement[i]);
				}
				else {
					printf("You can't add more items!");
				}
			}
		}
		else {
			printf("You can't add more items!");
		}
	}
}

template<typename E>
int Equipment<E>::slotsTaken() const {
	return this->slots;
}


template<class E>
bool Equipment<E>::isEmpty() const {
	if (this->slots == 0) return true;
	return false;
}


template<class E>
bool Equipment<E>::isFull() const {
	if (this->slots == 24) return true;
	return false;
}

void Equipment<Armor>::removeItem(Armor item) {
	for (int i = 0; i < equipement.size(); i++) {
		if (equipement[i].getArmorType() == item.getArmorType()) {
			equipement.erase(equipement.begin() + i);
			slots--;
		}
		else {
			printf("There is not such item to remove!\n");
		}
	}
}

void Equipment<Weapon>::removeItem(Weapon item) {
	for (int i = 0; i < equipement.size(); i++) {
		if (equipement[i].getWeaponTypeName() == item.getWeaponTypeName()) {
			if (equipement[i].getWeaponType() == 1) {
				slots--;
			}
			else if (equipement[i].getWeaponType() == 2) {
				slots -= 2;
			}
			equipement.erase(equipement.begin() + i);
		}
		else {
			printf("There is not such item to remove!\n");
		}
	}
}


void Equipment<Armor>::addItem(Armor item) {
	if (slots < 24) {
		slots++;
		equipement.push_back(item);
	}
	else {
		printf("You can't add more items!");
	}
}

void Equipment<Weapon>::addItem(Weapon item) {
	if (slots < 24) {
		if (item.getWeaponType() == 1) {
			slots++;
			equipement.push_back(item);
		}
		else if (item.getWeaponType() == 2) {
			if (slots + 2 < 24) {
				slots += 2;
				equipement.push_back(item);
			}
			else {
				printf("You can't add more items!");
			}
		}
	}
	else {
		printf("You can't add more items!");
	}
}

template<class E>
void Equipment<E>::setEmpty() {

	for (int i = 0; i < equipement.size(); i++) {
		equipement.erase(equipement.begin() + i);
	}
	this->slots = 0;
}


Weapon Equipment<Weapon>::bestItem() const {
	if (equipement.size() == 0) {
		return Weapon();
	}
	if (equipement.size() == 1) {
		return equipement[0];
	}
	else {
		Weapon weapon = equipement[0];
		for (int i = 0; i < equipement.size() - 1; i++) {
			if (equipement[i].getWeaponScore() < equipement[i + 1].getWeaponScore()) {
				weapon = equipement[i + 1];
			}
		}
		return weapon;
	}
}

Armor Equipment<Armor>::bestItem() const {
	Armor armor = equipement[0];
	if (equipement.size() == 0) {
		return Armor();
	}
	if (equipement.size() == 1) {
		return equipement[0];
	}
	else {
		for (int i = 0; i < equipement.size(); i++) {
			if (equipement[i].getGearscore() < equipement[i + 1].getGearscore()) {
				armor = equipement[i + 1];
			}
		}
	}

	return armor;
}


bool Equipment<Armor>::operator==(const Equipment& e) const {		
	double temp1 = 0;
	double temp2 = 0;
	for (int i = 0; i < equipement.size(); i++) {
		temp1 += equipement[i].getGearscore();
	}
	for (int i = 0; i < equipement.size(); i++) {
		temp2 += e.equipement[i].getGearscore();
	}
	return temp1 == temp2;
}

bool Equipment<Weapon>::operator==(const Equipment& e) const {			
	double temp1 = 0;
	double temp2 = 0;
	for (int i = 0; i < equipement.size(); i++) {
		temp1 += equipement[i].getWeaponScore();
	}
	for (int i = 0; i < equipement.size(); i++) {
		temp2 += e.equipement[i].getWeaponScore();
	}
	return temp1 == temp2;
}


bool Equipment<Armor>::operator!=(const Equipment& e) const {			
	double temp1 = 0;
	double temp2 = 0;
	for (int i = 0; i < equipement.size(); i++) {
		temp1 += equipement[i].getGearscore();
	}
	for (int i = 0; i < equipement.size(); i++) {
		temp2 += e.equipement[i].getGearscore();
	}
	return temp1 != temp2;
}

bool Equipment<Weapon>::operator!=(const Equipment& e) const {			
	double temp1 = 0;
	double temp2 = 0;
	for (int i = 0; i < equipement.size(); i++) {
		temp1 += equipement[i].getWeaponScore();
	}
	for (int i = 0; i < equipement.size(); i++) {
		temp2 += e.equipement[i].getWeaponScore();
	}
	return temp1 != temp2;
}

template<typename E>
Equipment<E>& Equipment<E>::operator=(const Equipment& e) {
	if (this != &e) {
		for (int i = 0; i < equipement.size(); i++) {
			equipement[i] = e.equipement[i];
		}
		this->slots = e.slots;
	}
	return *this;
}


template<class E>
int Equipment<E>::getEquipementSlots() const {
	return this->slots;
}

void Equipment<Armor>::print() const{
	for (int i = 0; i < equipement.size(); i++) {
		equipement[i].printArmor();
	}
}

void Equipment<Weapon>::print() const {
	for (int i = 0; i < equipement.size(); i++) {
		equipement[i].showWeapon();
	}
}

std::ostream& operator<<(std::ostream& out, const Equipment<Weapon>& in) {
	for (int i = 0; i < in.equipement.size(); i++) {
		out << in.equipement[i] << " " << in.slots << " ";
	}
	return out;
}

std::ostream& operator<<(std::ostream& out, const Equipment<Armor>& in) {
	for (int i = 0; i < in.equipement.size(); i++) {
		out << in.equipement[i] << " " << in.slots << " ";
	}
	return out;
}


#endif // !EQUIPEMENT