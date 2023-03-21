
#include "LeavingRequest.hpp"

LeavingRequest::LeavingRequest() : Request() {}

LeavingRequest::LeavingRequest(const std::string& sender)
	: Request("I want to leave!", sender) {}
