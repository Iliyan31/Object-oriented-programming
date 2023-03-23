#pragma once
#include "Base.hpp"

# define PI 3.14

class Circle :public Base {
public:
	Circle(const std::string& colour = " ", const size_t& radius = 0);

	size_t getradius() const;
	void setRadius(const size_t& radius);

	Base* clone() const;
	~Circle() = default;

	double getSeize() const;
private:
	size_t radius;
};