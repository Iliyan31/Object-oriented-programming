
#include "Error.hpp"

Error::Error(const std::string& message) {
	this->errorMessage = message;
}

std::string Error::get_message() const {
	return this->errorMessage;
}
