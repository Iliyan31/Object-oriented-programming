#pragma once
#include <iostream>

#define MAX_SECONDS 86399

class Timestamp {
private:
	unsigned short HH;
	unsigned short MM;
	unsigned short SS;
	//const unsigned int MAX_SECONDS = 86400;
public:
	void toTimestamp(unsigned int seconds);
	Timestamp add_to(const Timestamp& rhs);
	void add(const Timestamp& rhs);
	unsigned int to_seconds() const;
	void print() const;
};