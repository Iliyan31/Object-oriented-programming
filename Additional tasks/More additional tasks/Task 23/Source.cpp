
#include "Header.h"

int main() {
	Stack s;
	s.push('a');
	s.push('b');
	s.push('c');
	s.push('d');
	Stack t = s;
	s.print();
	StackIter si(t);
	char* ptr = NULL;
	while (ptr = si.getNext()) {
		std::cout << *ptr << std::endl;
	}

}