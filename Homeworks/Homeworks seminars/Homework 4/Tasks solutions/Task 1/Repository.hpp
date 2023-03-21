#pragma once

#include "Publishers.hpp"

class Repository {
public:
	void add(Subscribers*);
	Repository() = default;
	Repository(const Repository& r);
	Repository& operator=(const Repository& r);
	~Repository();
	Subscribers* get(const std::string& id) const;
private:
	std::vector<Subscribers*> subscribers;
};