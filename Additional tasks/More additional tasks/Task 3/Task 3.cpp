
#include <iostream>
#include <cmath> // atan2 - arctan y/x

const double PI = 3.14159265;

struct Polar {
	double radius;
	double angle;
};

struct Rect {
	double x;
	double y;
};

Polar rect_to_polar(const Rect& r) {
	Polar p;
	p.radius = sqrt(r.x * r.x + r.y * r.y);
	p.angle = atan2(r.y, r.x);
	return p;
}

Rect polar_to_rect(const Polar& p) {
	const double DEG_TO_RAD = PI / 180;
	Rect r;
	r.x = p.radius * cos(p.angle * DEG_TO_RAD);
	r.y = p.radius * sin(p.angle * DEG_TO_RAD);
	return r;
}

void show_polar(const Polar& p) {
	const double RAD_TO_DEG = 180 / PI;
	std::cout << "radius = " << p.radius;
	std::cout << ", angle = " << p.angle * RAD_TO_DEG;
	std::cout << " degrees.\n";
}

void show_rect(const Rect& r){
	std::cout << "Ox-> = " << r.x << ", Oy-> = " << r.y << "\n";
}


int main() {
	Rect r;
	Polar p;
	std::cout << "Choose the type of input: \n";
	std::cout << "r - for rectangular and "
		"p - for polar coordinates. \n";
	char ch;
	std::cin >> ch;
	switch (ch) {
	case 'r': std::cout << "Please insert rectangular coordinates: \n";
		while (std::cin >> r.x >> r.y) {
			p = rect_to_polar(r);
			show_polar(p);
			std::cout << "Next rectangular coordinates, "
				"for the end, please enter the string: end";
		}
		break;
	case 'p': std::cout << "Please enter the polar coordinates radius and angle: \n";
		while (std::cin >> p.radius >> p.angle) {
			r = polar_to_rect(p);
			show_polar(p);
			std::cout<<"Next coordinates, "
				"for the end, please enter the string: end";
		}
	}
	return 0;

}
