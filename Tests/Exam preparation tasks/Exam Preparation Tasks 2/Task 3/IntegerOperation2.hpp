#pragma once
#include<iostream>

class IntegerOperation2 {
public:
	IntegerOperation2();
	IntegerOperation2(const IntegerOperation2& from);
	IntegerOperation2& operator=(const IntegerOperation2& from);
	~IntegerOperation2();

	void insert(const int& integer);
	void sum();
	void sub();
	void multiply();
	
	int operator+(IntegerOperation2& integer);
	int operator-(IntegerOperation2& integer);
	int operator*(IntegerOperation2& integer);

	int getResult() const;

private:
	void copy_memory(int* destination, const int* source);
	void clear_memory(int* source);
	void resize();
	int* integer;
	int result;
	int capacity;
	int size;
};