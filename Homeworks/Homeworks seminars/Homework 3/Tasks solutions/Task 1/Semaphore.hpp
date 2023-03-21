
#ifndef SEMAPHORE
#define SEMAPHORE
#include "LimitedTwowayCounter.hpp"

class Semaphore : public LimitedTwowayCounter {
private:
	static bool flag;
public:
	Semaphore();
	Semaphore(bool flag);
	bool isAvailable() const;
	void wait();
	void signal();
};

#endif // !SEMAPHORE