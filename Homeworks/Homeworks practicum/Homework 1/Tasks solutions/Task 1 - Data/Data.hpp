
/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Iliyan Yordanov
* @idnumber 62546
* @task 1
* @compiler VC
*/


#ifndef DATA
#define DATA

#include <iostream>

const int SIZE_STR = 3;

class Date {
public:
	Date();
	Date(unsigned int _day, unsigned int _month, unsigned int _year);
	void showData(const Date& d);
	char* makeDaysAndMonths(const unsigned int& a);
	void validationData();
	bool isLeap() const;
	void addDays(const unsigned int& _day);
	void subtractDays(const unsigned int& _day);
	int daysTillChristmas() const;
	int daysTillEndOfTheYear() const;
	int daysTillBirthday(int _days, const int& _months, int _year);
	bool isAfter(const unsigned int& d1, const unsigned int& m1, const unsigned int& y1);

private:
	unsigned int day;
	unsigned int month;
	unsigned int year;
};

#endif // !DATA