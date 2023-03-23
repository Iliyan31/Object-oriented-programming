
#include "Header.h"

int main() {
	printf("Name of the client: ");
	char n1[MAX];
	std::cin.getline(n1, MAX);
	printf("Number of the bank account: ");
	char an1[MAX];
	std::cin.getline(an1, MAX);
	double b1;
	printf("Balance: "); std::cin >> b1;
	std::cin.ignore();
	BankAccount x(n1, an1, b1);
	x.print();
	x.put_in(200);
	x.print();
	x.draw(100);
	x.print();

	return 0;
	//printf("Name of the client: ");

}