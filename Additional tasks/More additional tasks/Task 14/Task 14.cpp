
#include "Header.h"

Stack::Stack() : top(EmptyStack) {}

Stack::Stack(const Stack& s) : top(s.top) {
	for (int i = 0; i <= top; i++) {
		items[i] = s.items[i];
	}
}

void Stack::push(char c){
	if (full()) printf("It is full \n");
	items[top++] = c;
}

char Stack::pop() {
	if (empty()) {
		printf("The stack is empty \n");
		return Emptyflag;
	}
		
	return items[top--];
}

bool Stack::empty() const {
	return top == EmptyStack;
}

bool Stack::full() const {
	return top == FullStack - 1;
}

void Stack::print() {
	for (int i = top; i >= 0; i--) {
		std::cout << pop() << std::endl;
	}
}