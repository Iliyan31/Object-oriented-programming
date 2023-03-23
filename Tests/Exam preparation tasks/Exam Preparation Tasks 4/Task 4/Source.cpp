
#include "Shop.hpp"

int main() {
	Drink d("Cola", "467", 1.50, 0);

	Shop s;
	s.AddItem(&d);
	s.print(1.60);
	s.searchItem("467");
	s.RemoveItem("467");
	s.print(1.60);
	s.searchItem("467");

	return 0;
}