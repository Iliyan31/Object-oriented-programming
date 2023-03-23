
#ifndef HEADER
#define HEADER

#include <iostream>
#include <string>
#include <stdlib.h>

const int MAX = 100;

class BankAccount {
private:
	char* name;
	char* accountnum;
	double balance;
public:
	BankAccount(const char* = "", const char* = "", double = 0.0);
	BankAccount(const BankAccount&);
	~BankAccount();
	void print() const;
	void put_in(double);
	void draw(double);
};

#endif // !HEADER

