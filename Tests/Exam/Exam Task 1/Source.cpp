#include "Shapes.hpp"

int main() {

	Circle c("red", 1);
	Rectangle r("blue", 5, 10);

	Shapes s;
	s.AddShape(&c);
	s.AddShape(&r);
	std::cout<<s.getAllCirclesSeizes()<<"\n";
	std::cout << s.getAllRectanglesSeizes();
	 s.getShape(0);
	return 0;
}