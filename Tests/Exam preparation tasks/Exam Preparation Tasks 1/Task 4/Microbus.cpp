
#include "Microbus.hpp"

Microbus::Microbus(const std::string& brand, const std::string& model, const std::string& problem, Severity severity, const size_t& year, Type type, bool hasPassengers)
	: Vehicle(brand, model, problem, severity, year, Type::Mocrobus), hasPassengers(hasPassengers) {}

bool Microbus::getHasPassengers() const
{
	return this->hasPassengers;
}

void Microbus::setHasPassengers(bool flag) {
	this->hasPassengers = flag;
}

Vehicle* Microbus::clone() {
	return new Microbus(*this);
}
