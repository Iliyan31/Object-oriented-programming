
#include "Header.h"

Stack::Stack() : top(EmptyStack) {}

Stack::Stack(const Stack& s) : top(s.top) {
	for (int i = 0; i <= top; i++) {
		items[i] = s.items[i];
	}
}

void Stack::push(char c) {
	if (full()) {
		printf("The stack is full \n");
		return;
	}
	items[top++] = c;
}

char Stack::pop() {
	if (empty()) {
		printf("The stack is full \n");
		return EmptyFlag;
	}
	return items[top--];
}

bool Stack::empty() const {
	return top == EmptyStack;
}

bool Stack::full() const {
	return top == FullStack - 1;
}

void Stack::print() const {
	for (int i = top; i >= 0; i--) {
		std::cout << pop() << std::endl;
	}
}

char* StackIter::getNext() {
	if (st->top = EmptyStack) {
		return 0;
	}
	return &st->items[st->top--];
}