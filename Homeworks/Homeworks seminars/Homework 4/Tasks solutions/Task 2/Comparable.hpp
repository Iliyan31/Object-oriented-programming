#pragma once
#include <iostream>
class Comparable {
public:
	virtual bool operator==(const Comparable* c) const = 0;
	virtual bool operator!=(const Comparable* c) const = 0;
	virtual ~Comparable() = default;
};