#pragma once
#include<iostream>
#include <string>

enum class Type {
	rectangle,
	circle,
	none
};

class Base {
public:
	Base(const std::string& colour = " ", const Type& type = Type::none);
	void SetColour(const std::string& colour);
	std::string getColour() const;

	virtual Base* clone() const = 0;
	virtual ~Base() = default;

	virtual double getSeize() const = 0;

private:
	Type type;
	std::string colour;
};