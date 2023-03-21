#pragma once

#include "Averager.hpp"
#include "Message.hpp"
#include "MovingAverager.hpp"
#include "PeriodicSampler.hpp"

class Publishers {
public:
	virtual void subscribe(Subscribers*) = 0;
	virtual void unsubscribe(Subscribers*) = 0;
	virtual void signal(const Message& m) = 0;
	~Publishers() = default;
protected:
	std::vector<Subscribers*> sub;
	std::vector<Message> allMessages;
};