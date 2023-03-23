
#include "Header.h"

Cylinder::Cylinder(double r, double h) : radius(r), height(h) {}

double Cylinder::getRadius() const { return radius; }
double Cylinder::getHeight() const { return height; }

SquarePyramid::SquarePyramid(double s, double h) : side(s), height(h) {};

double SquarePyramid::getSide() const { return side; }
double SquarePyramid::getHeight() const { return height; }

bool isHigher(const Cylinder& c, const SquarePyramid& s) {
	return c.height > s.height;
}


int main() {
	Cylinder c(12.5, 8.0);
	SquarePyramid s(5.2, 10.5);
	if (isHigher(c, s)) {
		printf("The cylinder is higher than the pyramid. \n");
	}
	else {
		printf("The pyramid is higher than the cylinder. \n");
	}

	return 0;
}