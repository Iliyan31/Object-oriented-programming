
/**
* Solution to homework assignment 2
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021 *
* @author Iliyan Yordanov
* @idnumber 62546
* @task 1
* @compiler VC
*/

#ifndef MONEY
#define MONEY

#include <iostream>
#include <cstring>
#include <vector>
#include <utility>

class Money {
private:
	std::vector<std::pair<unsigned int, std::string>> money;
public:

	void templ(unsigned int num1, unsigned int num2);
	Money();
	Money(std::vector<std::pair<unsigned int, std::string>> _money);
	Money(const Money& m);
	~Money() = default; 

	
	void addMoney(std::string typ, unsigned int sum);
	void takeMoney(std::string typ, unsigned int sum);
	void printMoney() const;
	void setEmpty();
	Money& operator+=(const Money& m);
	Money& operator-=(const Money& m);

	friend std::ostream& operator<<(std::ostream& out, const Money& in);
};

#endif // !MONEY