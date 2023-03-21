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

#include "magicCard.hpp"

Magic::Magic(std::string name, std::string effect, Type _type)
	: Base(name, effect), type(_type) {}

Type Magic::getType() const {
	return this->type;
}