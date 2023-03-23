

#ifndef HEADER
#define HEADER

#include <iostream>

class SquarePyramid;

class Cylinder {
private: 
	double radius;
	double height;
public:
	Cylinder(double = 0, double = 0);
	double getRadius() const;
	double getHeight() const;
	friend bool isHigher(const Cylinder&, const SquarePyramid&);
};

class SquarePyramid {
private:
	double side;
	double height;
public:
	SquarePyramid(double = 0, double = 0);
	double getSide() const;
	double getHeight() const;
	friend bool isHigher(const Cylinder&, const SquarePyramid&);
};

#endif // HEADER

