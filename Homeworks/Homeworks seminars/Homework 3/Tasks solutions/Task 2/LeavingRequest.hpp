
#ifndef LEAVINGREQUEST
#define LEAVINGREQUEST
#include "Request.hpp"

class LeavingRequest : public Request{
public:
	LeavingRequest();
	LeavingRequest(const std::string& sender);
};

#endif // !LEAVINGREQUEST