
#ifndef HEADER
#define HEADER

#include <iostream>

class Laptop {
private:
	Processor processor;
	char* model;
	double price;
	HardDrive hardDrives[3];
public:
	Laptop();
	Laptop(const char* modeel, double price);
	Laptop(const Laptop&);
	~Laptop();
	Laptop& operator=(const Laptop)
};


#endif // !HEADER


