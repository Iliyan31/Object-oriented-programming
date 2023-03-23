
#ifndef HEADER
#define HEADER
#include <iostream>

template<class T>
class Value {
public:
	Value(const T& vaule = T(), const size_t& code = 0);
	void setValue(const T& value);
	void setCode(const size_t& code);

	T getValue(const size_t& code) const;
	size_t getCode() const;

private:
	T value;
	size_t code;
};

template<class T>
Value<T>::Value(const T& vaule, const size_t& code) : value(vaule), code(code) {}

template<class T>
void Value<T>::setValue(const T& value) {
	this->value = value;
}

template<class T>
void Value<T>::setCode(const size_t& code) {
	this->code = code;
}

template<class T>
T Value<T>::getValue(const size_t& code) const {
	if (this->code == code) {
		return this->value;
	}
	else {
		printf("No code match!\n");
	}
}

template<class T>
size_t Value<T>::getCode() const {
	return this->code;
}

#endif // !HEADER