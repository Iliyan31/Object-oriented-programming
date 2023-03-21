
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

#ifndef ARMOR
#define ARMOR

#include <iostream>
#include <cstring>
#include <vector>
#include <utility>

enum class armorType {
	none,
	cloth, 
	leather, 
	mail
};

class Armor {
private:
	armorType type;
	unsigned int defence;
	std::vector<std::pair<std::string, unsigned int>> armEffects;
	int Gearscore;
public:
	void armorTempl(std::string, unsigned int);
	Armor();
	Armor(unsigned int _defence, armorType _type, std::vector<std::pair<std::string, unsigned int>> _armEffects, int _Gearscore);
	Armor(const Armor& a);
	~Armor() = default;

	int gearScoreCalculation(std::vector<std::pair<std::string, unsigned int>> _armEffects);

	void changeArmorType(armorType _type);
	void changeArmorDefence(unsigned int _defence);
	void addArmorEffect(std::string name, unsigned int addEffect);
	void deleteArmorEffect(std::string name);
	void changePowerOfArmorEffect(std::string name, unsigned int power);

	Armor& operator=(const Armor& a);
	int getArmorType() const;
	double getGearscore() const;  
	void printArmor() const;

	friend std::ostream& operator<<(std::ostream& out, const Armor& in);
};

#endif // !ARMOR