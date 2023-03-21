#pragma once
#include "Message.hpp"
#include <string>
#include <vector>
#include "Subscribers.hpp"

class MovingAverager : public Subscribers {
public:
	MovingAverager(const std::string& id, const size_t& windowSize);
	const size_t windowSize;
	void signal(const Message& m);
	int read() const;
	Subscribers* clone() const;
	~MovingAverager() = default;
};