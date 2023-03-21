
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


#include "Data.hpp"

Date::Date() : day(1), month(1), year(2000) {}

Date::Date(unsigned int _day, unsigned int _month, unsigned int _year)
	: day(_day), month(_month), year(_year) {
	validationData();
}


void Date::validationData() {
	bool flag = false;
	if (day == 0) flag = false;
	
	switch (month) {
	case 1: case 3: case 5: case 7: case 8: case 10: case 12: if (day <= 31) flag = true; break;
	case 4: case 6: case 9: case 11: if (day <= 30) flag = true; break;
	case 2: if (day <= 28 && !isLeap() || day <= 29 && isLeap()) flag = true; break;
	}
	
	if (flag == false) printf("This data is invalid!");
}

char* Date::makeDaysAndMonths(const unsigned int& a) {
	
	if (a < 10) {
		char* str = new char[SIZE_STR];
		for (int i = 0; i < SIZE_STR; i++) {
			switch (i) {
			case 0: str[0] = 0 + '0'; break;
			case 1: str[1] = a + '0'; break;
			case 2: str[2] = '\0';
			}
		}
		return str;
		delete[] str;
	}
	else {
		int num = a;
		char* str = new char[SIZE_STR];
		for (int i = 0; i < SIZE_STR; i++) {
			switch (i) {
			case 0: str[0] = '0'; str[1] = num % 10 + '0'; num /= 10; break;
			case 1: str[0] = num % 10 + '0'; break;
			case 2: str[2] = '\0';
			}
		}
		return str;
		delete[] str;
	}
}

bool Date::isLeap() const {
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0) return true;
			else return false;
		}
		else return true;
	}
	else return false;
}

void Date::addDays(const unsigned int& _day) {
	
	this->day +=_day;

	switch (month) {
	case 1: case 3: case 5: case 7: case 8: case 10:
		if (day > 31) {
			this->day -= 31;
			this->month += 1;
		}
		break;
	case 4: case 6: case 9: case 11:
		if (day > 30) {
			this->day -= 30;
			this->month += 1;
		}
		break;
	case 2:
		if (day > 28 && !isLeap()) {
			this->day -= 28;
			this->month += 1;
		}
		else if (day > 29 && isLeap()) {
			this->day -= 29;
			this->month += 1;
		}
		break;
	case 12:
		if (day > 31) {
			this->day -= 31;
			this->month -= 11;
			this->year += 1;
		}
	}
}
	
void Date::subtractDays(const unsigned int& _day) {
	int num = _day;
	num = day - _day;

	switch (month) {
	case 1:
		this->day = (31 + num);
		this->month += 11;
		this->year -= 1;
		break;
	case 3:
		if (day <= 28 && !isLeap()) {
			this->day = (28 + num);
			this->month -= 1;
		}
		else if (day <= 29 && isLeap()) {
			this->day = (29 + num);
			this->month -= 1;
		}
		break;

	case 2: case 4: case 6: case 9: case 11:
		this->day = (31 + num);
		this->month -= 1;
		break;

	case 5: case 7: case 8: case 10: case 12:
		this->day = (30 + num);
		this->month -= 1;
	}
}

int Date::daysTillChristmas() const {
	const unsigned int Christmas = 359;
	unsigned int days = day;
	
	const int arr[] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };

	days += arr[month - 1];
	if (isLeap() && month < 3) days++;
	days = Christmas - days;

	printf("Days until Christmas: ");
	return days;
}

int Date::daysTillEndOfTheYear() const {
	const unsigned int nextYear = 367;
	unsigned int days = day;

	const int arr[] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };

	days += arr[month - 1];
	if (isLeap() && month < 3) days++;
	days = nextYear - days;

	printf("Days until the end of the year: ");
	return days;
}

int Date::daysTillBirthday(int D, const int& M, int Y) {

	const int arr[] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };

	if (day > D && month >= M && year >= Y || month > M && year >= Y || year > Y) { 
		printf("The birthday was before the current day. \n");
	}

	Y = 365 * (Y - year);
	const unsigned int secondDays = D;

	if (month >= M) {

		D = day + ((arr[month - 1] - arr[M - 1]) - D);
		D = Y - D;
		if (day < secondDays) D++;
		if (isLeap() && M < 3) D++;
	}
	else if (month < M) {

		D = day + (365 - arr[M - 1] + arr[month - 1]) - D;
		D = Y - D + Y;
		if (day < secondDays) D++;
		if (isLeap() && month < 3) D++;
	}
	
	return D;
}

bool Date::isAfter(const unsigned int& d1, const unsigned int& m1, const unsigned int& y1) {
	printf("Is the date after the previously entered data? : ");
	return (day < d1 && month <= m1 && year <= y1 || month < m1 && year <= y1 || year < y1);
}

void Date::showData(const Date& d) {
	std::cout << "The data is: " << makeDaysAndMonths(day) << "." << makeDaysAndMonths(month)
		<< "." << year;
}