
#include "Header.h"

BankAccount::BankAccount(const char* n, const char* an, double b) : balance(b) {
	this->name = new char[strlen(n) + 1];
	if (!name) {
		printf("Error while passing the data \n");
		std::exit(1);
	}
	std::strcpy(name, n);
	this->accountnum = new char[strlen(an) + 1];
	if (!accountnum) {
		printf("Error while passing the data \n");
		std::exit(1);
	}
	std::strcpy(accountnum, an);
}

BankAccount::BankAccount(const BankAccount& b) : balance(b.balance) {
	name = new char[strlen(b.name) + 1];
	if (!name) {
		printf("Error while passing the data \n");
		std::exit(1);
	}
	std::strcpy(name, b.name);

	accountnum = new char[strlen(b.accountnum) + 1];
	if (!accountnum) {
		printf("Error while passing the data \n");
		std::exit(1);
	}
	std::strcpy(accountnum, b.accountnum);
}

BankAccount::~BankAccount() {
	delete[] accountnum;
	delete[] name;
}

void BankAccount::print() const {
	std::cout << "Nmae of the client: " << name << std::endl;
	std::cout << "Number of the bank account: " << accountnum << std::endl;
	std::cout << "Balance: " << balance << std::endl;
}

void BankAccount::put_in(double cash) {
	if (cash >= 0) {
		balance += cash;
	}
	else {
		printf("Invalid input of cash! \n");
	}
}

void BankAccount::draw(double cash) {
	if (cash < 0) {
		printf("Invalid input of cash! \n");
	}
	else {
		if (cash <= balance) {
			balance -= cash;
		}
		else {
			printf("The balance doesn't have enough money! \n");
		}
	}
}
