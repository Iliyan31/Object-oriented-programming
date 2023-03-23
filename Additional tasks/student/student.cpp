
#include "Header.h"

Student::Student(const char* name = "Default") : fn(0), grade(0) {
	strcpy(this->name, name);
}

//Student::Student(int _fn, double _grade) : fn(_fn), grade(_grade) {}

//Student::Student(const char* name, int fn, double grade) {
//	this->name = new char[8];
//	strcpy(this->name, name);
//	strlen(name);
//	this->fn = fn;
//	this->grade = grade;
//}
Student::Student(const Student& other) {
	fn = other.fn;
	grade = other.grade;
	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);
}

Student::~Student() {
	delete[] name;
}

Student& Student::operator=(const Student& s) {
	if (this != &s) {
		this->fn = s.fn;
		this->grade = s.grade;
	}
	return *this;
}

void Student::print() const {
	std::cout << "fn: " << fn << " grade: " << grade << std::endl;
}