
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

#ifndef WEAPON
#define WEAPON

#include <iostream>
#include <cstring>
#include <vector>
#include <utility>

enum class WeaponType {
	none,
	axe,
	sword,
	dagger,
	mace,
	staff
};

enum class Type {
	none,
	oneHanded,
	twoHanded
};

class Weapon {
private:

	WeaponType nameWeapon;
	Type type;
	std::pair<unsigned int, unsigned int> hitDamage;
	std::vector<std::pair<std::string, unsigned int>> effects;
	double WeaponScore;

public:
	void weaponTempl(std::string name, unsigned int num);
	Weapon();
	Weapon(WeaponType _nameWeapon, Type _type, std::pair<unsigned int, unsigned int> _hitDamage, std::vector<std::pair<std::string, unsigned int>> _effects);
	Weapon(const Weapon& w);
	~Weapon() = default;

	double WeaponScoreCalculation(Type _type, std::pair<unsigned int, unsigned int> _hitDamage, std::vector<std::pair<std::string, unsigned int>> _effects);

	void changeWeapon(WeaponType weapon);
	void changeWeaponType(Type _type);
	void addWeaponEffect(std::string name, unsigned int addEffect);
	void deleteWeaponEffect(std::string name);
	void changePowerOfWeaponEffect(std::string name, unsigned int power);
	void showWeapon() const;

	int getWeaponType() const;
	int getWeaponTypeName() const;
	double getWeaponScore() const;  
	
	Weapon& operator=(const Weapon& w);
	friend std::ostream& operator<<(std::ostream& out, const Weapon& in);
};

#endif // !WEAPON
