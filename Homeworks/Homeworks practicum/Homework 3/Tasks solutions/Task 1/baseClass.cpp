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

#include "baseClass.hpp"

Base::Base(std::string _name, std::string _effect) : name(_name), effect(_effect) {}

std::string Base::getName() const {
	return this->name;
}

std::string Base::getEffect() const {
	return this->effect;
}