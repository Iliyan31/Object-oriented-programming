
#include "Counter.hpp"

Counter::Counter() {
	this->initial = 0;
	this->step = 1;
}

Counter::Counter(int initial) {
	this->initial = initial;
	this->step = 1;
}

Counter::Counter(int initial, unsigned step) {
	this->initial = initial;
	this->step = step;
}

void Counter::increment() {
	this->initial+=this->step;
}

int Counter::getTotal() const {
	return this->initial;
}

unsigned Counter::getStep() const {
	return this->step;
}