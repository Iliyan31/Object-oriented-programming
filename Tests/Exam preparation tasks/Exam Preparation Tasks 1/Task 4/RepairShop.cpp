
#include "RepairShop.hpp"

Repair::Repair(const Repair& r) {
	this->justCopy(r);
}

Repair& Repair::operator=(const Repair& r) {
	if (this != &r) {
		this->justClear();
		this->justCopy(r);
	}
	return *this;
}

void Repair::addVehicle(Vehicle* v) {
	if (hasCapacity(v)) {
		this->repair.push_back(v->clone());
	}
	else {
		printf("There is no more capacity!\n");
	}
}

size_t Repair::CapacityOfRepairShop() const {
	size_t sum = 0;
	for (int i = 0; i < this->repair.size(); i++) {
		sum += (int)this->repair[i]->getSeverity();
	}
	return sum;
}

bool Repair::hasCapacity(Vehicle* v) const {
	return (this->CapacityOfRepairShop() + (int)v->getSeverity()) <= 10;
}

Repair::~Repair() {
	this->justClear();
}

void Repair::justCopy(const Repair& r) {
	this->repair.clear();
	this->capacity = r.capacity;
	for (int i = 0; i < r.repair.size(); i++) {
		this->addVehicle(r.repair[i]);
	}
}

void Repair::justClear() {
	for (int i = 0; i < this->repair.size(); i++) {
		delete this->repair[i];
	}
	this->repair.clear();
	this->capacity = 0;
}
