
#include "Repository.hpp"

void Repository::add(Subscribers* subs) {
	this->subscribers.push_back(subs->clone());
}

Repository::Repository(const Repository& r) {
	this->subscribers.clear();
	for (int i = 0; i < r.subscribers.size(); i++) {
		this->add(r.subscribers[i]);
	}
}

Repository& Repository::operator=(const Repository& r) {
	if (this != &r) {
		this->subscribers.clear();
		for (int i = 0; i < r.subscribers.size(); i++) {
			this->add(r.subscribers[i]);
		}
	}
	return *this;
}

Repository::~Repository() {
	for (int i = 0; i < subscribers.size(); i++) {
		delete subscribers[i];
	}
	this->subscribers.clear();
}

Subscribers* Repository::get(const std::string& id) const {	
	for (int i = 0; i < subscribers.size(); i++) {
		if (subscribers[i]->getID() == id) {
			return this->subscribers[i];
		}
	}
	return nullptr;
}