
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

#include "armor.hpp"

void Armor::armorTempl(std::string name, unsigned int num) {
	std::pair<std::string, unsigned int> temp;
	temp.first = name;
	temp.second = num;
	this->armEffects.push_back(temp);
}

Armor::Armor() : defence(0), Gearscore(0) {
	type = armorType::none;
	for (int i = 0; i < armEffects.size(); i++) {
		armorTempl("None", 0);
	}
}

Armor::Armor(unsigned int _defence, armorType _type, std::vector<std::pair<std::string, unsigned int>> _armEffects, int _Gearscore) : defence(_defence), Gearscore(_Gearscore), type(_type) {
	for (int i = 0; i < _armEffects.size(); i++) {
		armorTempl(_armEffects[i].first, _armEffects[i].second);
	}
}

Armor::Armor(const Armor& a) : defence(a.defence), Gearscore(a.Gearscore), type(a.type) {
	for (int i = 0; i < a.armEffects.size(); i++) {
		armorTempl(a.armEffects[i].first, a.armEffects[i].second);
	}
}

int Armor::gearScoreCalculation(std::vector<std::pair<std::string, unsigned int>> _armEffects) {
	int score = 0;
	for (int i = 0; i < _armEffects.size(); i++) {
		score += _armEffects[i].second;
	}
	return score;
}

void Armor::changeArmorType(armorType _type){
	this->type = _type;
}

void Armor::changeArmorDefence(unsigned int _defence) {
	this->defence = _defence;
}

void Armor::addArmorEffect(std::string name, unsigned int addEffect) {
	armorTempl(name, addEffect);
	this->Gearscore = gearScoreCalculation(armEffects);
}

void Armor::deleteArmorEffect(std::string name) {
	for (int i = 0; i < armEffects.size(); i++) {
		if (armEffects.at(i).first == name) {
			armEffects.erase(armEffects.begin() + i);
		}
	}
	this->Gearscore = gearScoreCalculation(armEffects);
}

void Armor::changePowerOfArmorEffect(std::string name, unsigned int power) {
	for (int i = 0; i < armEffects.size(); i++) {
		if (armEffects.at(i).first == name) {
			armEffects.at(i).second = power;
		}
	}
	this->Gearscore = gearScoreCalculation(armEffects);
}

Armor& Armor::operator=(const Armor& a) {
	if (this != &a) {
		this->defence = a.defence;
		this->Gearscore = a.Gearscore;
		this->type = a.type;
		for (int i = 0; i < a.armEffects.size(); i++) {
			armorTempl(a.armEffects[i].first, a.armEffects[i].second);
		}
	}
	return *this;
}

int Armor::getArmorType() const {
	switch (type) {
	case armorType::cloth: return 1; break;
	case armorType::leather: return 2; break;
	case armorType::mail: return 3; break;
	}
}

double Armor::getGearscore() const {
	return this->Gearscore;
}

void Armor::printArmor() const {
	switch (type) {
	case armorType::cloth: printf("cloth"); break;
	case armorType::leather: printf("leather"); break;
	case armorType::mail: printf("mail"); break;
	}
	std::cout << std::endl;
	std::cout << defence << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < armEffects.size(); i++) {
		std::cout << armEffects[i].first << std::endl;
		std::cout << armEffects[i].second << std::endl;
	}
	std::cout << std::endl;
	std::cout << Gearscore;
}

std::ostream& operator<<(std::ostream& out, const Armor& in) {
	std::string temp = " ";
	switch (in.type) {
	case armorType::cloth: temp = "cloth"; break;
	case armorType::leather: temp = "leather"; break;
	case armorType::mail: temp = "mail"; break;
	}
	for (int i = 0; i < in.armEffects.size(); i++) {
		out << temp << " " << in.defence << " " << in.armEffects[i].first << " " << in.armEffects[i].second << " ";
	}
	return out;
}