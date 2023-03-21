
#include "Subscribers.hpp"

Subscribers::Subscribers(const std::string& id)
	: id(id) {}

std::string Subscribers::getID() const {
	return this->id;
}