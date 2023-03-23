#pragma once

#include <iostream>
#include <cstring>

const int MaxLengthName = 30;
const int PATIENTS = 200;

class Date {
public:
	Date();
	Date(int d, int m, int y);
	int Day() const;
	int Month() const;
	int Year() const;
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	void print() const;
private:
	int theDay;
	int theMonth;
	int theYear;
};


class Patient {
public:
	Patient();
	Patient(char*, const Date&, int);
	const char* getname() const;
	Date getDOB() const;
	int getVisits() const;
	void print() const;
private:
	char Name[MaxLengthName];
	Date DOB;
	int Visits;
};

class Doctor {
private:
	char Name1[MaxLengthName];
	Patient PatientList[PATIENTS];
	int PatientsRegistered;
public:
	Doctor(char*);
	const char* getname() const;
	void registerPatient(const Patient& p);
	double average() const;
	void printUpper(int) const;
};


//#ifdef HEADER;
//#define HEADER;
//
//
//
//
//#endif // HEADER;
