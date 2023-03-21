#pragma once

#include "Publishers.hpp"

class SimplePublisher : public Publishers {
public:
	void subscribe(Subscribers*);
	void unsubscribe(Subscribers*);
	void signal(const Message& m);
	~SimplePublisher() = default;
};