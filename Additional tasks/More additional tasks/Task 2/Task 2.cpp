
#include <iostream>
#include <cmath>

struct Triangle {
	double a, b, c;
};

void create_triangle(Triangle& t) {
	bool tri;
	do {
		std::cout << "a, b, c (the sides of the triangle): ";
		std::cin >> t.a >> t.b >> t.c;
		tri = (t.a > 0) && (t.b > 0) && (t.c > 0)
			&& (t.a + t.b > t.c) && (t.a + t.c > t.b) && (t.b + t.c > t.a);
	} while (!tri);
}

void show_triangle(const Triangle& t) {
	std::cout << "triangle(" << t.a << "," << t.b << "," << t.c << ")\n";
}

double perimeter_triangle(const Triangle& t) {
	return t.a + t.b + t.c;
}

double surface_triangle(const Triangle& t) {
	double p = perimeter_triangle(t);
	return sqrt(p * (p - t.a) * (p - t.b) * (p - t.c));
}


int main() {
	Triangle t; 
	create_triangle(t);
	show_triangle(t);
	std::cout << "Perimeter: " << perimeter_triangle(t) << std::endl;
	std::cout << "Surface: " << surface_triangle(t) << std::endl;
	return 0;
}