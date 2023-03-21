
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

#include "weapons.hpp"

void Weapon::weaponTempl(std::string name, unsigned int num) {
	std::pair<std::string, unsigned int> temp;
	temp.first = name;
	temp.second = num;
	this->effects.push_back(temp);
}



Weapon::Weapon() : nameWeapon(WeaponType::none) ,type(Type::none), WeaponScore(0) {
	this->hitDamage.first = 0;
	this->hitDamage.second = 0;

	for (int i = 0; i < effects.size(); i++) {
		weaponTempl("None", 0);
	}
}



Weapon::Weapon(WeaponType _nameWeapon, Type _type, std::pair<unsigned int, unsigned int> _hitDamage, std::vector<std::pair<std::string, unsigned int>> _effects) {
	
	this->nameWeapon = _nameWeapon;

	if (nameWeapon == WeaponType::staff) {
		this->type = Type::twoHanded;
	}
	else if (nameWeapon == WeaponType::dagger) {
		this->type = Type::oneHanded;
	}
	else {
		this->type = _type;
	}

	this->hitDamage.first = _hitDamage.first;
	this->hitDamage.second = _hitDamage.second;

	for (int i = 0; i < _effects.size(); i++) {
		weaponTempl(_effects[i].first, _effects[i].second);
	}	

	this->WeaponScore = WeaponScoreCalculation(_type, _hitDamage, _effects);
}




Weapon::Weapon(const Weapon& w) {
	this->nameWeapon = w.nameWeapon;
	this->type = w.type;
	this->hitDamage.first = w.hitDamage.first;
	this->hitDamage.second = w.hitDamage.second;

	for (int i = 0; i < w.effects.size(); i++) {
		weaponTempl(w.effects[i].first, w.effects[i].second);
	}
	this->WeaponScore = WeaponScoreCalculation(w.type, w.hitDamage, w.effects);
}


double Weapon::WeaponScoreCalculation(Type _type, std::pair<unsigned int, unsigned int> _hitDamage, std::vector<std::pair<std::string, unsigned int>> _effects) {
	double temp = 0;
	temp += _hitDamage.first;
	temp += _hitDamage.second;
	temp /= 2;
	for (int i = 0; i < _effects.size(); i++) {
		temp += _effects[i].second;
	}
	if (_type == Type::oneHanded) {
		temp *= 0.75;
	}
	else if (_type == Type::twoHanded) {
		temp *= 1.5;
	}
	return temp;
}



void Weapon::changeWeapon(WeaponType _weapon) {

	this->nameWeapon = _weapon;

	switch (_weapon) {
	case WeaponType::staff: this->type = Type::twoHanded; break;
	case WeaponType::dagger: this->type = Type::oneHanded; break;
	}
}

void Weapon::changeWeaponType(Type _type) {
	if (nameWeapon == WeaponType::staff) {
		if (_type == Type::oneHanded) {
			printf("You can't change staff to one-handed!");
		}
		else if (_type == Type::twoHanded) {
			this->type = Type::twoHanded;
		}
	}
	else if (nameWeapon == WeaponType::dagger) {
		if (_type == Type::oneHanded) {
			this->type = Type::oneHanded;
		}
		else if (_type == Type::twoHanded) {
			printf("You can't change dagger to two-handed!");
		}
	}
	else {
		this->type = _type;
	}
}


void Weapon::addWeaponEffect(std::string name, unsigned int addEffect) {
	weaponTempl(name, addEffect);
	this->WeaponScore = WeaponScoreCalculation(type, hitDamage, effects);
}



void Weapon::deleteWeaponEffect(std::string name) {
	for (int i = 0; i < effects.size(); i++) {
		if (effects.at(i).first == name) {
			effects.erase(effects.begin() + i);
		}
	}
	this->WeaponScore = WeaponScoreCalculation(type, hitDamage, effects);
}



void Weapon::changePowerOfWeaponEffect(std::string name, unsigned int power) {
	for (int i = 0; i < effects.size(); i++) {
		if (effects.at(i).first == name) {
			effects.at(i).second = power;
		}
	}
	this->WeaponScore = WeaponScoreCalculation(type, hitDamage, effects);
}

void Weapon::showWeapon() const {
	switch (nameWeapon) {
	case WeaponType::staff: printf("staff"); break;
	case WeaponType::dagger: printf("dagger"); break;
	case WeaponType::mace: printf("mace"); break;
	case WeaponType::sword: printf("sword"); break;
	case WeaponType::axe: printf("axe"); break;
	}
	std::cout << std::endl;
	switch (type) {
	case Type::oneHanded: printf("1"); break;
	case Type::twoHanded: printf("2"); break;
	}
	std::cout << hitDamage.first << std::endl;
	std::cout << hitDamage.second << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < effects.size(); i++) {
		std::cout << effects[i].first << std::endl;
		std::cout << effects[i].second << std::endl;
	}
	std::cout << WeaponScore << std::endl;
}

int Weapon::getWeaponType() const {
	switch (type) {
	case Type::oneHanded: return 1; break;
	case Type::twoHanded: return 2; break;
	}
}

int Weapon::getWeaponTypeName() const {
	switch (nameWeapon) {
	case WeaponType::axe: return 1; break;
	case WeaponType::dagger: return 2; break;
	case WeaponType::mace: return 3; break;
	case WeaponType::staff: return 4; break;
	case WeaponType::sword: return 5; break;
	}
}

double Weapon::getWeaponScore() const {
	return this->WeaponScore;
}

Weapon& Weapon::operator=(const Weapon& w) {
	if (this != &w) {
		this->nameWeapon = w.nameWeapon;
		this->type = w.type;
		this->hitDamage.first = w.hitDamage.first;
		this->hitDamage.second = w.hitDamage.second;

		for (int i = 0; i < w.effects.size(); i++) {
			weaponTempl(w.effects[i].first, w.effects[i].second);
		}
		this->WeaponScore = WeaponScoreCalculation(w.type, w.hitDamage, w.effects);
	}
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Weapon& in) {
	std::string temp = " ";
	switch (in.nameWeapon) {
	case WeaponType::staff: temp = "staff"; break;
	case WeaponType::dagger: temp = "dagger"; break;
	case WeaponType::mace: temp = "mace"; break;
	case WeaponType::sword: temp = "sword"; break;
	case WeaponType::axe: temp = "axe"; break;
	}
	
	std::string temp2 = " ";
	switch (in.type) {
	case Type::oneHanded: temp2 = "oneHanded"; break;
	case Type::twoHanded:temp2 = "twoHanded"; break;
	}

	for (int i = 0; i < in.effects.size(); i++) {
		out << temp << " " << temp2 << " " << in.hitDamage.first << " " << in.hitDamage.second << " " << in.effects[i].first << " " << in.effects[i].second << " " << in.WeaponScore << " ";
	}
	return out;
}