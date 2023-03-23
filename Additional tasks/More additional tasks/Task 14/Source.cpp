
#include "Header.h"

int main() {
	Stack s;
	s.push('a');
	s.push('b');
	s.push('c');
	Stack t = s;
	s.print();
	if (!t.empty()) {
		std::cout << t.pop() << std::endl;
	}
	t.print();

	return 0;
}