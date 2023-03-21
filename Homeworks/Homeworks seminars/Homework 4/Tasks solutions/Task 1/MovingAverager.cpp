
#include "MovingAverager.hpp"

MovingAverager::MovingAverager(const std::string& id, const size_t& windowSize)
	: Subscribers(id), windowSize(windowSize) {}

void MovingAverager::signal(const Message& m) {
	this->messages.push_back(m);
}

int MovingAverager::read() const {
	int sum = 0;
	if (messages.size() == 0) return 0;
	if (this->windowSize >= this->messages.size()) {
		for (int i = 0; i < messages.size(); i++) {
			sum += messages[i].getData();
		}
		return sum / messages.size();
	}
	else {
		const int temp = messages.size() - this->windowSize;
		for (int i = temp; i < messages.size(); i++) {
			sum += messages[i].getData();
		}
		return sum / this->windowSize;
	}
}

Subscribers* MovingAverager::clone() const {
	return new MovingAverager(*this);
}