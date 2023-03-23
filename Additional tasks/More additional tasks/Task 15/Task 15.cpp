
#include "Header.h"

Date::Date() : theDay(1), theMonth(1), theYear(2000) {}

Date::Date(int d, int m, int y) : theDay(d), theMonth(m), theYear(y) {}

int Date::Day() const { return theDay; }
int Date::Month() const { return theMonth; }
int Date::Year() const { return theYear; }

void Date::setDay(int d) {
	this->theDay = d;
}

void Date::setMonth(int m) {
	this->theMonth = m;
}

void Date::setYear(int y) {
	this->theYear = y;
}

void Date::print() const {
	std::cout << theDay << "." << theMonth << "." << theYear << std::endl;
}




Patient::Patient() : Visits(0) {}

Patient::Patient(char* n, const Date& d, int v) : DOB(d), Visits(v) {
	strcpy_s(Name, n);
}

const char* Patient::getname() const { return Name; }
Date Patient::getDOB() const { return DOB; }
int Patient::getVisits() const { return Visits; }

void Patient::print() const {
	std::cout << "Name:" << Name << std::endl;
	std::cout << "Date: ";  DOB.print();
	std::cout << "Number of visits: " << Visits << std::endl;
}






Doctor::Doctor(char* n) {
	strcpy_s(Name1, n);
	this->PatientsRegistered = 0;
}

const char* Doctor::getname() const { return Name1; }

void Doctor::registerPatient(const Patient& p) {
	PatientList[PatientsRegistered] = p;
	PatientsRegistered++;
}

double Doctor::average() const {
	int totalVisits = 0;
	for (int i = 0; i < PatientsRegistered; i++) {
		totalVisits += PatientList[i].getVisits();
	}
	if (PatientsRegistered != 0) return double(totalVisits) / PatientsRegistered;
	return 0;
}

void Doctor::printUpper(int limit) const {
	printf("Patients with visiths above the limit! \n");
	for (int i = 0; i < PatientsRegistered; i++) {
		if (PatientList[i].getVisits() > limit)
			PatientList[i].print();
	}
}