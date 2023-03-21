
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
#include "money.hpp"

#include "Inventory.hpp"
#include "Equipement.hpp"
#include "Backpack.hpp"
#include <iostream>
#include <cstring>
#include <vector>

int main() {

	/*std::pair<unsigned int, unsigned int> hit;
	hit.first = 12;
	hit.first = 50;
	std::vector<std::pair<std::string, unsigned int>> vec;
	std::pair<std::string, unsigned int> weap;
	weap.first = "Spell";
	weap.first = 50;
	vec.push_back(weap);
	Weapon w(WeaponType::staff, Type::twoHanded, hit, vec);*/
	/*w.changeWeapon(WeaponType::dagger);
	w.showWeapon();*/



	std::vector<std::pair<unsigned int, std::string>> vec;
	std::pair<unsigned int, std::string> temp1;
	temp1.first = 1;
	temp1.second = "gold";
	std::pair<unsigned int, std::string> temp2;
	temp2.first = 15;
	temp2.second = "silver";
	vec.push_back(temp1);
	vec.push_back(temp2);


	Money m(vec);
	m.addMoney("silver", 95);
	//m.takeMoney("silver", 220);
	m.printMoney();
	Money p(vec);
	p.addMoney("silver", 75);
	//m += p;
	m -= p;
	m.printMoney();


	/*std::vector<Weapon> vec2;
	vec2.push_back(w);

	Equipment<Weapon> e(vec2);
	e.setEmpty();
	e.addItem(w);
	e.removeItem(w);
	std::cout<<e.slotsTaken();
	std::cout << e.isEmpty();
	std::cout << e.isFull();
	
	
	e.bestItem();*/

	/*Backpack<Money> b(m);
	std::cout<<b.isEmpty();
	std::cout << b.isFull();
	b.addItem(m);
	b.removeItem(m);*/

	
	/*std::vector<std::pair<unsigned int, materialsType>> materials;
	std::pair<unsigned int, materialsType> temp1;
	temp1.first = 10;
	temp1.second = materialsType::herbs;
	std::pair<unsigned int, materialsType> temp2;
	temp2.first = 10;
	temp2.second = materialsType::ores;
	std::pair<unsigned int, materialsType> temp3;
	temp3.first = 10;
	temp3.second = materialsType::cloth;
	std::pair<unsigned int, materialsType> temp4;
	temp4.first = 10;
	temp4.second = materialsType::essence;

	materials.push_back(temp1);
	materials.push_back(temp2);
	materials.push_back(temp3);
	materials.push_back(temp4);

	Materials m(materials);*/
	/*std::cout << m.getsSlots();
	m.setEmpty();
	m.addMaterial(50, materialsType::essence);
	m.removeMaterial(30, materialsType::essence);
	std::cout << m.getsSlots();*/

	/*Backpack<Materials> b(m);
	std::cout << b.isEmpty();
	std::cout << b.isFull();
	b.addItem(m);
	b.removeItem(m);
	b.setEmpty();
	std::cout << b.isEmpty();*/

	Inventory<Backpack<Money>> P;
	Inventory<Backpack<Money>> T;
	if (P == T)
	{
		std::cout << "Yes\n";
	}
	std::cout << P;

	return 0;
}