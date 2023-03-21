
#include "TestCase.hpp"

TestCase::TestCase(const std::string& name, const Error& error) {
	this->TestCaseName = name;
	this->error.setType(error);
	this->error.setMessage(error.getMessage());
}

std::string TestCase::getName() const {
	return this->TestCaseName;
}

bool TestCase::isPassing() const {
	if ((this->error.getType() == ErrorType::BuildFailed) || (this->error.getType() == ErrorType::FailedAssertion)) {
		return false;
	}
	else if ((this->error.getType() == ErrorType::None) || (this->error.getType() == ErrorType::Warning)) {
		return true;
	}
}

bool TestCase::hasError() const {
	if ((this->error.getType() == ErrorType::BuildFailed) || (this->error.getType() == ErrorType::FailedAssertion) || (this->error.getType() == ErrorType::Warning)) {
		return true;
	}
	else if (this->error.getType() == ErrorType::None) {
		return false;
	}
}

ErrorType TestCase::getErrorType() const {
	return this->error.getType();
}

std::string TestCase::getErrorMessage() const{
	std::string _name;
	for (int i = 0; i < strlen(error.getMessage()); i++) {
		_name.push_back(error.getMessage()[i]);
	}
	return _name;
}