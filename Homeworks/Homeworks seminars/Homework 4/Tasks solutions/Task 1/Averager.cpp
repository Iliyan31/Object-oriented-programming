#include "Averager.hpp"

Averager::Averager(const std::string& id) : Subscribers(id) {}

void Averager::signal(const Message& m) {
	this->messages.push_back(m);
}

int Averager::read() const {
	int sum = 0;
	for (int i = 0; i < this->messages.size(); i++) {
		sum += messages[i].getData();
	}
	if (messages.size() == 0) {
		return 0;
	}
	return sum / messages.size();
}

Subscribers* Averager::clone() const {
	return new Averager(*this);
}