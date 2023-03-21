
#include "LimitedCounter.hpp"

LimitedCounter::LimitedCounter() : Counter(), max(0) {}

LimitedCounter::LimitedCounter(int max) : Counter(), max(max) {}

LimitedCounter::LimitedCounter(int max, int initial) : Counter(initial), max(max) {}

LimitedCounter::LimitedCounter(int max, int initial, unsigned step) : Counter(initial, step), max(max) {}

void LimitedCounter::increment() {
	if ((this->initial + this->step) <= this->max) {
		this->initial += this->step;
	}
	else {
		std::cerr << "You can't go above " << this->max << "!" << std::endl;
	}
}

int LimitedCounter::getMax() const {
	return this->max;
}