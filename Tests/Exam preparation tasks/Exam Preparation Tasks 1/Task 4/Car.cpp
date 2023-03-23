
#include"Car.hpp"

Car::Car(const std::string& brand, const std::string& model, const std::string& problem, Severity severity, const size_t& year, Type type, bool isPersonal)
	: Vehicle(brand, model, problem, severity, year, Type::Car), isPersonal(isPersonal) {
}

bool Car::getIsCompany() const {
	return isPersonal == false;
}

bool Car::getIsPersonal() const {
	return isPersonal == true;
}

void Car::setIspersonal(bool flag) {
	this->isPersonal = flag;
}

Vehicle* Car::clone() {
	return new Car(*this);
}
