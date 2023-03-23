
#include "Player.hpp"

int main() {

	Magic m("1", 2, 3, "4");

	Player p;
	p.addCard(&m);
	p.printAllcards();
	p.removeCard(0);
	p.printAllcards();

	return 0;
}