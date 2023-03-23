#pragma once
#include "Base.hpp"

class Rectangle : public Base {
public:
	Rectangle(const std::string& colour = " ", const size_t& lenght = 0, const size_t& width = 0);
	void setWidth(const size_t& width);
	void setLenght(const size_t& lenght);

	size_t getLenght() const;
	size_t getWidth() const;

	Base* clone() const;
	~Rectangle() = default;

	double getSeize() const;
private:
	size_t lenght;
	size_t width;
};