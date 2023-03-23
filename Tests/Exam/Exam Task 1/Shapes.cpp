#include "Shapes.hpp"

Shapes::Shapes(const Shapes& s)
{
	this->justCopy(s);
}

Shapes& Shapes::operator=(const Shapes& s)
{
	if (this != &s) {
		this->justClear();
		this->justCopy(s);
	}
	return *this;
}

Shapes::~Shapes()
{
	this->justClear();
}

void Shapes::AddShape(Base* b)
{
	this->shapes.push_back(b->clone());
}

void Shapes::RemoveShape(const int& index)
{
	if (index < this->shapes.size()) {
		delete this->shapes[index];
	}
}

double Shapes::getAllCirclesSeizes() const {
	double sum = 0;
	for (int i = 0; i < this->shapes.size(); i++) {
		Circle* circle = dynamic_cast<Circle*>(this->shapes[i]);
		if (circle) {
			sum += circle->getSeize();
		}
	}
	return sum;
}

double Shapes::getAllRectanglesSeizes() const
{
	double sum = 0;
	for (int i = 0; i < this->shapes.size(); i++) {
		Rectangle* rec = dynamic_cast<Rectangle*>(this->shapes[i]);
		if (rec) {
			sum += rec->getSeize();
		}
	}
	return sum;
}

void Shapes::getShape(const int& index) const
{
	if (index < this->shapes.size()) {
		Rectangle* rec = dynamic_cast<Rectangle*>(this->shapes[index]);
		Circle* circle = dynamic_cast<Circle*>(this->shapes[index]);

		if (rec) {
			std::cout << rec->getColour() << " " << rec->getLenght() << " " << rec->getWidth() << "\n";
		}
		if (circle) {
			std::cout << circle->getColour() << " " << circle->getradius() << "\n";
		}
	}
}

void Shapes::justCopy(const Shapes& s)
{
	this->shapes.clear();
	for (int i = 0; i < s.shapes.size(); i++) {
		this->AddShape(s.shapes[i]);
	}
}

void Shapes::justClear()
{
	for (int i = 0; i < this->shapes.size(); i++) {
		delete this->shapes[i];
	}
	this->shapes.clear();
}
