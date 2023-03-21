
#ifndef COUNTER
#define COUNTER
#include <iostream>

class Counter {
protected:
	int initial;
	int step;
public:
	Counter();
	Counter(int initial);
	Counter(int initial, unsigned step);
	void increment();
	int getTotal() const;
	unsigned getStep() const;
};

#endif // !COUNTER