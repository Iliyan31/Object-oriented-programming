
#include "LimitedTwowayCounter.hpp"

LimitedTwowayCounter::LimitedTwowayCounter()
	: LimitedCounter(), min(0), TwowayCounter(), Counter() {}

LimitedTwowayCounter::LimitedTwowayCounter(int min, int max) 
	: LimitedCounter(max), min(min), TwowayCounter(), Counter() {}

LimitedTwowayCounter::LimitedTwowayCounter(int min, int max, int initial) 
	: LimitedCounter(max, initial), min(min), TwowayCounter(initial), Counter(initial) {}

LimitedTwowayCounter::LimitedTwowayCounter(int min, int max, int initial, unsigned step) 
	: LimitedCounter(max, initial, step), min(min), TwowayCounter(initial, step), Counter(initial, step) {}

void LimitedTwowayCounter::increment() {				
	if ((this->initial + this->step) <= this->max) {
		this->initial += this->step;
	}
	else {
		std::cerr << "You can't go above " << this->max << "!" << std::endl;
	}
}

void LimitedTwowayCounter::decrement() {
	if ((this->initial - this->step) >= this->min) {
		this->initial -= this->step;
	}
	else {
		std::cerr << "You can't go below " << this->min << "!" << std::endl;
	}
}

int LimitedTwowayCounter::getMin() const {
	return this->min;
}