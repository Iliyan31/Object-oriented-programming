
#ifndef LIMITEDTWOWAYCOUNTER
#define LIMITEDTWOWAYCOUNTER
#include "LimitedCounter.hpp"
#include "TwowayCounter.hpp"

class LimitedTwowayCounter : public LimitedCounter, public TwowayCounter {
protected:
	int min;
public:
	LimitedTwowayCounter();
	LimitedTwowayCounter(int min, int max);
	LimitedTwowayCounter(int min, int max, int initial);
	LimitedTwowayCounter(int min, int max, int initial, unsigned step);
	void increment();  
	void decrement();
	int getMin() const;
};

#endif // !LIMITEDTWOWAYCOUNTER