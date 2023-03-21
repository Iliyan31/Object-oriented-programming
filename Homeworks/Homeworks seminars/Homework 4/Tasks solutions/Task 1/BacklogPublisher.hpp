#pragma once

#include "Publishers.hpp"

class BacklogPublisher : public Publishers{
public:

	void subscribe(Subscribers*);
	void unsubscribe(Subscribers*);
	void signal(const Message& m);
	~BacklogPublisher() = default;
};