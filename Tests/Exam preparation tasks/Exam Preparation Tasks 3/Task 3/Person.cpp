
#include "Person.hpp"

Person::Person() {
	this->name = new char[1];
	this->name[0] = '\0';

	this->lastName = new char[1];
	this->lastName[0] = '\0';
}

Person::Person(const char* _name, const char* _lastname) {
	this->setName(_name);
	this->setLastName(_lastname);
}

Person::Person(const Person& p) {
	this->setName(p.name);
	this->setLastName(p.lastName);
}

Person& Person::operator=(const Person& p) {
	if (this != &p) {
		this->setName(p.name);
		this->setLastName(p.lastName);
	}
	return *this;
}

Person::~Person() {
	delete[] this->name;
	delete[] this->lastName;
}

void Person::setName(const char* _name) {
	delete[] this->name;
	this->name = new char[strlen(_name) + 1];
	strcpy_s(this->name, strlen(_name) + 1, _name);
}

void Person::setLastName(const char* _lastname) {
	delete[] this->lastName;
	this->lastName = new char[strlen(_lastname) + 1];
	strcpy_s(this->lastName, strlen(_lastname) + 1, _lastname);
}

char* Person::getName() const {
	return this->name;
}

char* Person::getLastName() const {
	return this->lastName;
}

std::ostream& operator<<(std::ostream& out, const Person& p) {
	out << p.getName() << " " << p.getLastName() << "\n";
	return out;
}

std::istream& operator>>(std::istream& in, Person& p) {
	char buffer[100];
	in >> buffer;
	p.setName(buffer);

	in >> buffer;
	p.setLastName(buffer);
	return in;
}
