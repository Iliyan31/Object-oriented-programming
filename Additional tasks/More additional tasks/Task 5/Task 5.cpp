
#include <iostream>
#include <cmath>

struct Point {
	int x;
	int y;
};

void create_point(Point& point) {
	std::cout << "Ox -> "; std::cin >> point.x;
	std::cout << "Oy -> "; std::cin >> point.y;
}

void show_point(const Point& point) {
	std::cout << "Point: (" << point.x << ", " << point.y << ")";
}

double sideOfTriangle(const Point& p1, const Point& p2) {
	return sqrt((p2.x - p1.x)* (p2.x - p1.x) + (p2.y - p1.y)* (p2.y - p1.y));
}

struct Triangle {
	Point A, B, C;
};

void create_triangle(Triangle& t) {
	std::cout << "Enter three dots that can be points of the triangle: \n";
	create_point(t.A);
	create_point(t.B);
	create_point(t.C);
}

void show_triangle(const Triangle& t) {
	std::cout << "Triangle: (";  show_point(t.A);
	std::cout << ", "; show_point(t.B);
	std::cout << ", "; show_point(t.C);
	std::cout << ") \n";
}

double perimeter_triangle(const Triangle& t) {
	double a = sideOfTriangle(t.B, t.C);
	double b = sideOfTriangle(t.A, t.C);
	double c = sideOfTriangle(t.A, t.B);
	return a + b + c;
}

double surface_triangle(const Triangle& t) {
	double a = sideOfTriangle(t.B, t.C);
	double b = sideOfTriangle(t.A, t.C);
	double c = sideOfTriangle(t.A, t.B);
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}


int main() {
	Triangle t;
	create_triangle(t);
	show_triangle(t);
	std::cout << "Perimeter: " << perimeter_triangle << std::endl;
	std::cout << "Surface: " << surface_triangle << std::endl;
	return 0;
}