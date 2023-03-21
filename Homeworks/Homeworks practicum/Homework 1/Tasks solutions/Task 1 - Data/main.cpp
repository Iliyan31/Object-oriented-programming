
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

int main() {
	Date d;
	Date();
	Date s(15, 2, 1999);
	//std::cout << std::endl;
	//s.addDays(10);
	//s.subtractDays(40);
	std::cout<< s.daysTillChristmas();
	std::cout << std::endl;
	std::cout << s.daysTillEndOfTheYear();
	std::cout << std::endl;
	s.validationData();
	s.showData(s);
	std::cout << std::endl;
	std::cout << s.isAfter(12, 10, 2015) << std::endl;;
	std::cout << s.daysTillBirthday(15, 3, 2000);

	return 0;
}