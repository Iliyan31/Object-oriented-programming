#ifndef PROTECTEDVALUE
#define PROTECTEDVALUE
#include <iostream>
#include <exception>

template<typename T>
class ProtectedValue {
public:
	ProtectedValue(const T& value = T(), const size_t& code = 0);
	T getValue(const size_t& code) const;
	size_t getCode() const;
	//void setCode(const size_t& code);
	//void setValue(const T& value);

private:
	T value;
	size_t code;
};


template<typename T>
class ProtectedArray {
public:
	ProtectedArray();
	ProtectedArray(ProtectedValue<T>* arr, const size_t& size);
	ProtectedArray(const ProtectedArray& p);
	ProtectedArray& operator=(const ProtectedArray& p);
	void add(T& value, const size_t& size);
	T getValue(const size_t& code, const size_t& index) const;
	void setSize(const size_t& size);
	~ProtectedArray();

private:
	ProtectedValue<T>* arr;
	size_t size;
};

#endif // !PROTECTEDVALUE
