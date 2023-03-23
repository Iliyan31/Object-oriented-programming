
#include "IntegerOperation2.hpp"

IntegerOperation2::IntegerOperation2() : capacity(1), size(0), result(0)
{
	this->integer = new int[1];
}

IntegerOperation2::IntegerOperation2(const IntegerOperation2& from) : capacity(from.capacity), size(from.size)
{
	this->copy_memory(this->integer, from.integer);
}

IntegerOperation2& IntegerOperation2::operator=(const IntegerOperation2& from)
{
	if (this != &from) {
		this->capacity = from.capacity;
		this->size = from.size;
		this->clear_memory(this->integer);
		this->copy_memory(this->integer, from.integer);
	}
	return *this;
}

IntegerOperation2::~IntegerOperation2()
{
	this->clear_memory(this->integer);
}

void IntegerOperation2::insert(const int& integer) {
	if (this->size == this->capacity) {
		this->resize();
	}
	this->integer[this->size] = integer;
	this->size++;
}

void IntegerOperation2::sum()
{
	this->result = 0;
	for (int i = 0; i < this->size; i++) {
		this->result += this->integer[i];
	}
}

void IntegerOperation2::sub()
{
	this->result = 0;
	for (int i = 0; i < this->size; i++) {
		this->result -= this->integer[i];
	}
}

void IntegerOperation2::multiply()
{
	this->result = 0;
	for (int i = 0; i < this->size; i++) {
		this->result *= this->integer[i];
	}
}

int IntegerOperation2::operator+(IntegerOperation2& integer) {
	this->sum();
	integer.sum();
	return this->getResult() + integer.getResult();
}

int IntegerOperation2::operator-(IntegerOperation2& integer)
{
	this->sub();
	integer.sub();
	return this->getResult() + integer.getResult();
}

int IntegerOperation2::operator*(IntegerOperation2& integer)
{
	this->multiply();
	integer.multiply();
	return this->getResult() + integer.getResult();
}

int IntegerOperation2::getResult() const {
	return this->result;
}

void IntegerOperation2::copy_memory(int* destination,  const int* source)
{
	destination = new int[this->capacity];
	for (int i = 0; i < this->size; i++) {
		destination[i] = source[i];
	}
}

void IntegerOperation2::clear_memory(int* source)
{
	delete[] source;
}

void IntegerOperation2::resize()
{
	int* newMemory = new int[this->capacity * 2];
	for (int i = 0; i < this->size; i++) {
		newMemory[i] = this->integer[i];
	}
	this->capacity *= 2;
	this->clear_memory(this->integer);
	this->integer = newMemory;
	this->clear_memory(newMemory);
}
