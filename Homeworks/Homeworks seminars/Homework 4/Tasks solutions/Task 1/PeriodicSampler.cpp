
#include "PeriodicSampler.hpp"

PeriodicSampler::PeriodicSampler(const std::string& id, const size_t& period)
	: Subscribers(id), period(period) {}

void PeriodicSampler::signal(const Message& m) {
	this->messages.push_back(m);
}

int PeriodicSampler::read() const {
	int temp = 0;
	for (int i = 0; i < messages.size(); i++) {
		if (i != 0 && i % period != 0) {
			continue;
		}
		else if (i % period == 0) {
			temp = messages[i].getData();
		}
	}
	return temp;
}


Subscribers* PeriodicSampler::clone() const {
	return new PeriodicSampler(*this);
}