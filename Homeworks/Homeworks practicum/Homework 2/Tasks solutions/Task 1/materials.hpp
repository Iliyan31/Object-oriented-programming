
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

#ifndef MATERIALS
#define MATERIALS

#include <iostream>
#include <cstring>
#include <vector>
#include <utility>

enum class materialsType {
	herbs, 
	ores, 
	cloth, 
	essence,
	none
};

class Materials {
private:

	std::vector<std::pair<unsigned int, materialsType>> materials;
	unsigned int slots;
public:

	void materialsTempl(unsigned int, unsigned int, unsigned int, unsigned int);
	Materials();
	Materials(std::vector<std::pair<unsigned int, materialsType>> _materials);
	Materials(const Materials& m);
	~Materials() = default;

	void addMaterial(unsigned int num, materialsType _type);
	void removeMaterial(unsigned int num, materialsType _type);
	int printMaterials() const;
	int printMaterialsQuantity() const;

	int MaterialSlots(std::vector<std::pair<unsigned int, materialsType>> _materials);
	int getsSlots() const;
	void setEmpty();
	Materials& operator+=(const Materials& m);
	Materials& operator-=(const Materials& m);

	friend std::ostream& operator<<(std::ostream& out, const Materials& in);
	void printMater() const;
};

#endif // !MATERIALS