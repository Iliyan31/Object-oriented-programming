
#ifndef HEADER
#define HEADER

#include <iostream>

#define MaxStack 100
#define FullStack MaxStack
#define EmptyStack -1
#define EmptyFlag '\0'

class StackIter;

class Stack {
private:
	friend StackIter;
	char items[MaxStack];
	int top;
public:
	Stack();
	Stack(const Stack& s);
	void push(char c);
	char pop();
	bool empty() const;
	bool full() const;
	void print() const;
};

class StackIter {
private:
	Stack* st;
public:
	StackIter(Stack& s) {
		st = &s;
	}
	char* getNext();
};

#endif // !HEADER

