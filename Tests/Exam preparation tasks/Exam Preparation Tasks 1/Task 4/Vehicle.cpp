
#include "Vehicle.hpp"

Vehicle::Vehicle(const std::string& brand, const std::string& model, const std::string& problem, Severity severity, const size_t& year, Type type)
	: brand(brand), model(model), problem(problem), severity(severity), yearOfProduction(year), type(type) {}

void Vehicle::setBrand(const std::string& brand)
{
	this->brand = brand;
}

void Vehicle::setModel(const std::string& model)
{
	this->model = model;
}

void Vehicle::setProblem(const std::string& problem)
{
	this->problem = problem;
}

void Vehicle::setSeverity(const Severity& severity)
{
	this->severity = severity;
}

void Vehicle::setYear(const size_t& year)
{
	this->yearOfProduction = year;
}

std::string Vehicle::getBrand() const
{
	return this->brand;
}

std::string Vehicle::getModel() const
{
	return this->model;
}

std::string Vehicle::getProblem() const
{
	return this->problem;
}

Severity Vehicle::getSeverity() const
{
	return this->severity;
}

size_t Vehicle::getYear() const
{
	return this->yearOfProduction;
}
