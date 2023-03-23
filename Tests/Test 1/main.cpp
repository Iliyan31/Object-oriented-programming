
#include <iostream>
#include <string>
#include "DesktopPC.hpp"
#include "Laptop.hpp"

int main() {
	DesktopPC d(3, 2, 1000, 75);
	Laptop l(1, 3, 2, 1500);
	l.getPriceInEuro();
}