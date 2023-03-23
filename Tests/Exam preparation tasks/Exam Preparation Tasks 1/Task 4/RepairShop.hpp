
#ifndef REPAIRSHOP
#define REPAIRSHOP
#include "Car.hpp"
#include "Microbus.hpp"
#include <vector>

class Repair {
public:
	Repair() = default;
	Repair(const Repair& r);
	Repair& operator=(const Repair&r);

	void addVehicle(Vehicle* v);
	size_t CapacityOfRepairShop() const;
	bool hasCapacity(Vehicle* v) const;

	~Repair();
private:
	std::vector<Vehicle*> repair;
	size_t capacity;
	void justCopy(const Repair& r);
	void justClear();
};

#endif // !REPAIRSHOP

