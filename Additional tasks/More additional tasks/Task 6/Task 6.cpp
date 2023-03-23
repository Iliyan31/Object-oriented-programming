
#include <iostream>
#include <cmath>

const int SIZE_max = 100;

struct Point {
	double x, y;
};

void create_point(Point& p) {
	std::cout << "Ox -> : "; std::cin >> p.x;
	std::cout << "Oy -> : "; std::cin >> p.y;
}

void show_point(const Point& p) {
	std::cout << "Point: (" << p.x << ", " << p.y << ") \n";
}

double segment(const Point& p1, const Point& p2) {
	return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

void read_points(int n, Point* P) {
	for (int i = 0; i < n; i++) {
		std::cout << "x, y = ";
		create_point(P[i]);
	}
}

void show_points(int n, Point* P) {
	for (int i = 0; i < n; i++) {
		show_point(P[i]);
	}
}

double max_distance(int n, Point* P) {
	double max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			double temp = segment(P[i], P[j]);
			if (temp > max) max = temp;
		}
	}
	return max;
}

int main() {
	int n;
	do {
		std::cout << "Please insert value of n - from 2 to " << SIZE_max << ": ";
		std::cin >> n;
	} while (n < 2 || n > 100);
	Point P[SIZE_max];
	read_points(n, P);
	show_points(n, P);
	std::cout << "The max distance between this points is: " << max_distance(n, P) << std::endl;
	return 0;
}