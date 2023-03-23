#pragma once
#include "Circle.hpp"
#include "Rectangle.hpp"
#include <vector>

class Shapes {
public:
	Shapes() = default;
	Shapes(const Shapes& s);
	Shapes& operator=(const Shapes& s);
	~Shapes();

	void AddShape(Base* b);
	void RemoveShape(const int& index);

	double getAllCirclesSeizes() const;
	double getAllRectanglesSeizes() const;

	void getShape(const int& index) const;


private:
	void justCopy(const Shapes& s);
	void justClear();
	std::vector<Base*> shapes;
};