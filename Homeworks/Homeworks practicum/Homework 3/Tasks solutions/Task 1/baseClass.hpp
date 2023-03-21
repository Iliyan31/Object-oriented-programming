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

#ifndef BASE
#define BASE
#include <iostream>
#include <string>
class Base {
protected:
	std::string name;
	std::string effect;
public:
	Base(std::string _name = " ", std::string _effect = " ");
	std::string getName() const;
	std::string getEffect() const;
};

#endif // !BASE