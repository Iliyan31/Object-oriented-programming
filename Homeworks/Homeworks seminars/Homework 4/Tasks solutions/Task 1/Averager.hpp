#pragma once
#include "Message.hpp"
#include <string>
#include <vector>
#include "Subscribers.hpp"

class Averager : public Subscribers {
public:
	Averager(const std::string& id);
	void signal(const Message&);
	int read() const;
	Subscribers* clone() const;
	~Averager() = default;
};