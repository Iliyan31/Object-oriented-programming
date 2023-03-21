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

#ifndef MAGIC
#define MAGIC
#include "baseClass.hpp"

enum class Type {
	none,
	trap,
	buff,
	spell
};

class Magic : virtual public Base {
protected:
	Type type;
public:
	Magic(std::string name = " ", std::string effect = " ", Type _type = Type::none);
	Type getType() const;
};

#endif // !MAGIC