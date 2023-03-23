
#include "Header.h"

int main() {
	Timestamp a;
	a.toTimestamp(86400 / 2 - 1);
	a.print();
	std::cout << a.to_seconds() << std::endl;
	Timestamp secs;
	secs.toTimestamp(10000);
	secs.print();
	secs.add(secs);
	a.print();
	a.add_to(secs).print();
	return 0;
}