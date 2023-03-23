
#ifndef VEHICLE
#define VEHICLE
#include <iostream>
#include <string>

enum class Severity {
	None = 0,
	Low = 1,
	Medium = 3,
	High = 5
};

enum class Type {
	Car, 
	Mocrobus,
	none
};

class Vehicle {
public:
	Vehicle(const std::string& brand = " ", const std::string& model = " ", 
		const std::string& problem = "", Severity severity = Severity::None, const size_t& year = 0, Type type = Type::none);
	void setBrand(const std::string& brand);
	void setModel(const std::string& model);
	void setProblem(const std::string& problem);
	void setSeverity(const Severity& severity);
	void setYear(const size_t& year);

	std::string getBrand() const;
	std::string getModel() const;
	std::string getProblem() const;
	Severity getSeverity() const;
	size_t getYear() const;

	virtual Vehicle* clone() = 0;
	virtual ~Vehicle() = default;

protected:
	std::string brand;
	std::string model;
	std::string problem;
	Severity severity;
	size_t yearOfProduction;
	Type type;
};

#endif // !VEHICLE
