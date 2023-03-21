
#include "SimplePublisher.hpp"

void SimplePublisher::subscribe(Subscribers* subs) {
	if (subs != nullptr) {
		this->sub.push_back(subs);
	}
}

void SimplePublisher::unsubscribe(Subscribers* subs) {
	for (int i = 0; i < sub.size(); i++) {
		if (this->sub[i]->getID() == subs->getID()) {
			sub.erase(sub.begin() + i);
		}
	}
}

void SimplePublisher::signal(const Message& m) {
	allMessages.push_back(m);
	for (int i = 0; i < sub.size(); i++) {
		sub[i]->signal(m);
	}
}