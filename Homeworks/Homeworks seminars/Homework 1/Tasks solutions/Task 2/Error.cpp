
#include "Error.hpp";

bool Error::hasMessage() const {
	if (this->type == ErrorType::None) {
		return false;
	}
	return true;
}

const char* Error::getMessage() const {

	if (this->type == ErrorType::None) return nullptr;
	return this->ErrorMessage;
}

ErrorType Error::getType() const {
	return this->type;
}

Error Error::newNone() {
	Error NoneError;
	NoneError.type = ErrorType::None;
	NoneError.ErrorMessage = nullptr;
	return NoneError;
}

Error Error::newBuildFailed(const char* message) {
	Error BuildFailed;
	BuildFailed.type = ErrorType::BuildFailed;
	BuildFailed.ErrorMessage = new char[strlen(message) + 1];
	strcpy_s(BuildFailed.ErrorMessage, strlen(message) + 1, message);

	return BuildFailed;
}

Error Error::newWarning(const char* message) {
	Error Warning;
	Warning.type = ErrorType::Warning;
	Warning.ErrorMessage = new char[strlen(message) + 1];
	strcpy_s(Warning.ErrorMessage, strlen(message) + 1, message);

	return Warning;
}

Error Error::newFailedAssertion(const char* message) {
	Error FailedAssertion;
	FailedAssertion.type = ErrorType::FailedAssertion;

	FailedAssertion.ErrorMessage = new char[strlen(message) + 1];
	strcpy_s(FailedAssertion.ErrorMessage, strlen(message) + 1, message);

	return FailedAssertion;
}

void Error::setMessage(const char* str) {
	delete[] ErrorMessage;
	if (str == nullptr) {
		ErrorMessage = new char[1];
		ErrorMessage[0] = '\0';
	}
	else {
		this->ErrorMessage = new char[strlen(str) + 1];
		strcpy_s(ErrorMessage, strlen(str) + 1, str);
	}
}

void Error::setType(const Error& e) {
	this->type = e.getType();
}

Error::Error() : type(ErrorType::None) {
	this->ErrorMessage = new char[1];
	ErrorMessage[0] = '\0';
}

Error::Error(const Error& _error) : type(_error.type) {

	if (_error.ErrorMessage == nullptr) {
		ErrorMessage = new char[1];
		ErrorMessage[0] = '\0';
	}
	else {
		this->ErrorMessage = new char[strlen(_error.ErrorMessage) + 1];
		strcpy_s(ErrorMessage, strlen(_error.ErrorMessage) + 1, _error.ErrorMessage);
	}
}

Error& Error::operator=(const Error& _error){
	if (this != &_error) {
		delete[] ErrorMessage;
		this->ErrorMessage = new char[strlen(_error.ErrorMessage) + 1];
		strcpy_s(ErrorMessage, strlen(_error.ErrorMessage) + 1, _error.ErrorMessage);
		this->type = _error.type;
	}
	return *this;
}

Error::~Error(){
	delete[] ErrorMessage;
}