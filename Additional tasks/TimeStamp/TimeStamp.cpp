
#include "Header.h"

void Timestamp::toTimestamp(unsigned int seconds) {
	if (seconds > MAX_SECONDS) {
		seconds = seconds % MAX_SECONDS;
	}
	HH = seconds / (60 * 60);
	MM = (seconds / 60) % 60;
	SS = seconds % 60;
}

Timestamp Timestamp::add_to(const Timestamp& rhs) {
	Timestamp result;
	result.toTimestamp(this->to_seconds() + rhs.to_seconds());
	return result;
}

void Timestamp::add(const Timestamp& rhs) {
	this->toTimestamp(this->to_seconds() + rhs.to_seconds());

}

unsigned int Timestamp::to_seconds() const {
	return HH * (60 * 60) + MM * (60) + SS;
}


void Timestamp::print() const {
	std::cout << HH << ":" << MM << ":" << SS << std::endl;
}

