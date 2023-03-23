#pragma once

#include <iostream>

class Student {
private:
	int fn;
	double grade;
	char* name;
	//static f;
public:
	Student(const char* name = "Default");
	//Student(const char* name = "default",  int _fn = 0, double _grade = 0);
	~Student();
	//Student(const Student& other);
	Student& operator=(const Student&);
	void print() const;
};

//class Example -> Example* this;