
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

#include "materials.hpp"

void Materials::materialsTempl(unsigned int num1, unsigned int num2, unsigned int num3, unsigned int num4) {
	std::pair<unsigned int, materialsType> temp1;
	temp1.first = num1;
	temp1.second = materialsType::herbs;
	std::pair<unsigned int, materialsType> temp2;
	temp2.first = num2;
	temp2.second = materialsType::ores;
	std::pair<unsigned int, materialsType> temp3;
	temp3.first = num3;
	temp3.second = materialsType::cloth;
	std::pair<unsigned int, materialsType> temp4;
	temp4.first = num4;
	temp4.second = materialsType::essence;

	materials.push_back(temp1);
	materials.push_back(temp2);
	materials.push_back(temp3);
	materials.push_back(temp4);
}


Materials::Materials() :slots(0) {
	materialsTempl(0, 0, 0, 0);
}

Materials::Materials(std::vector<std::pair<unsigned int, materialsType>> _materials) {
	materialsTempl(_materials[0].first, _materials[1].first, _materials[2].first, _materials[3].first);
	this->slots = MaterialSlots(materials);
}

Materials::Materials(const Materials& m) {
	materialsTempl(m.materials[0].first, m.materials[1].first, m.materials[2].first, m.materials[3].first);
	this->slots = MaterialSlots(materials);
}


void Materials::addMaterial(unsigned int num, materialsType _type) {
	for (int i = 0; i < materials.size(); i++) {
		if (materials[i].second == _type) {
			materials[i].first += num;
		}
	}
	this->slots = MaterialSlots(materials);
}

void Materials::removeMaterial(unsigned int num, materialsType _type) {
	for (int i = 0; i < materials.size(); i++) {
		if (materials[i].second == _type) {
			if (num <= materials[i].first) {
				materials[i].first -= num;
			}
			else {
				printf("You can't take that much materials!\n");
				break;
			}
		}
	}
	this->slots = MaterialSlots(materials);
}

int Materials::printMaterials() const {
	for (int i = 0; i < materials.size(); i++) {
		switch (materials[i].second) {
		case materialsType::herbs: return 1; break;
		case materialsType::ores: return 2; break;
		case materialsType::cloth: return 3; break;
		case materialsType::essence: return 4; break;
		}
	}
}

int Materials::printMaterialsQuantity() const {
	for (int i = 0; i < materials.size(); i++) {
		switch (materials[i].second) {
		case materialsType::herbs: return materials[0].first; break;
		case materialsType::ores: return materials[1].first; break;
		case materialsType::cloth: return materials[2].first; break;
		case materialsType::essence: return materials[3].first; break;
		}
	}
}

int Materials::MaterialSlots(std::vector<std::pair<unsigned int, materialsType>> _materials) {
	int size = 0;
	int temp = 0;

	for (int i = 0; i < materials.size(); i++) {
		if (i != 3) {
			temp = materials[i].first;
			size += (temp / 20);
		}
		else {
			temp = materials[i].first;
			size += (temp / 10);
		}
	}
	return size;
}

int Materials::getsSlots() const {
	return this->slots;
}

void Materials::setEmpty() {
	materials[0].first = 0;
	materials[1].first = 0;
	materials[2].first = 0;
	materials[3].first = 0;
	this->slots = 0;
}

Materials& Materials::operator+=(const Materials& m) {
	if (this != &m) {
		for (int i = 0; i < materials.size(); i++) {
			materials[i].first += m.materials[i].first;
		}
	}
	return *this;
}

Materials& Materials::operator-=(const Materials& m) {
	if (this != &m) {
		for (int i = 0; i < materials.size(); i++) {
			if (materials[i].first - m.materials[i].first < 0) {
				continue;
			}
			else {
				materials[i].first -= m.materials[i].first;
			}
		}
	}
	return *this;	
}

void Materials::printMater() const {
	for (int i = 0; i < materials.size(); i++) {
		switch (materials[i].second) {
		case materialsType::herbs: printf("herbs"); break;
		case materialsType::ores: printf("ores"); break;
		case materialsType::cloth: printf("cloth"); break;
		case materialsType::essence: printf("essence"); break;
		}
		std::cout << std::endl;
		switch (materials[i].second) {
		case materialsType::herbs: printf("1"); break;
		case materialsType::ores: printf("2"); break;
		case materialsType::cloth: printf("3"); break;
		case materialsType::essence: printf("4"); break;
		}
	}
}

std::ostream& operator<<(std::ostream& out, const Materials& in) {
	for (int i = 0; i < in.materials.size(); i++) {
		std::string temp = " ";
		switch (in.materials[i].second) {
		case materialsType::herbs: temp = "herbs"; break;
		case materialsType::ores: temp = "ores"; break;
		case materialsType::cloth: temp = "cloth"; break;
		case materialsType::essence: temp = "essence"; break;
		}
		out << in.materials.at(i).first << " " << temp << " ";
	}
	return out;
}