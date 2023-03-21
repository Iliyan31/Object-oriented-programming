
#include "BacklogPublisher.hpp"

void BacklogPublisher::subscribe(Subscribers* subs) {
	if (subs != nullptr) {
		this->sub.push_back(subs);
	}
	for (int i = 0; i < allMessages.size(); i++) {
		sub[sub.size() - 1]->signal(allMessages[i]);
	}
}

void BacklogPublisher::unsubscribe(Subscribers* subs) {
	for (int i = 0; i < sub.size(); i++) {
		if (this->sub[i]->getID() == subs->getID()) {
			sub.erase(sub.begin() + i);
		}
	}
}

void BacklogPublisher::signal(const Message& m) {
	allMessages.push_back(m);
	for (int i = 0; i < sub.size(); i++) {
		sub[i]->signal(m);
	}
}