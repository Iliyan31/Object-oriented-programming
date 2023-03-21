
#include "Semaphore.hpp"

bool Semaphore::flag = false;

Semaphore::Semaphore() : LimitedTwowayCounter() {}

Semaphore::Semaphore(bool flag) 
	: LimitedTwowayCounter(0, 1, 0, 1) {
	if (flag == true) {
		this->initial = 1;
	}
}

bool Semaphore::isAvailable() const {
	return this->flag == true;
}

void Semaphore::wait() {
	if ((this->initial - this->step) >= this->min) {
		this->initial -= this->step;
	}
	else {
		std::cerr << "You can't go below " << this->min << "!" << std::endl;
	}
}

void Semaphore::signal() {
	if ((this->initial + this->step) <= this->max) {
		this->initial += this->step;
	}
	else {
		std::cerr << "You can't go above " << this->max << "!" << std::endl;
	}
}