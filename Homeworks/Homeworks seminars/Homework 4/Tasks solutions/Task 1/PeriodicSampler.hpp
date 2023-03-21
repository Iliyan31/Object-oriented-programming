#pragma once
#include "Message.hpp"
#include <string>
#include <vector>
#include "Subscribers.hpp"

class PeriodicSampler : public Subscribers {
public:
	PeriodicSampler(const std::string& id, const size_t& period);
	const size_t period;
	void signal(const Message& m);
	int read() const;
	Subscribers* clone() const;
	~PeriodicSampler() = default;
};