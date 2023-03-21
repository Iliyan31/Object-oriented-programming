#pragma once
#include "Message.hpp"
#include <iostream>
#include <string> 
#include <vector>

class Subscribers {
public:
	const std::string id;
	Subscribers(const std::string& id = " ");
	std::string getID() const;
	virtual void signal(const Message& m) = 0;
	virtual int read() const = 0;
	virtual Subscribers* clone() const = 0;
	virtual ~Subscribers() = default;
protected:
	std::vector<Message> messages;
};