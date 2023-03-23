#pragma once

#include <iostream>

const int MaxStack = 100;
const int FullStack = MaxStack;

const int EmptyStack = -1;
const char Emptyflag = '\0';

class Stack {
private:
	char items[MaxStack];
	int top;
public:
	Stack();
	Stack(const Stack&);
	void push(char c);
	char pop();
	bool empty() const;
	bool full() const;
	void print();
};