
#include "ProtectedValue.hpp"


template<typename T>
ProtectedValue<T>::ProtectedValue(const T& value, const size_t& code)
	: value(value), code(code) {}

template<typename T>
T ProtectedValue<T>::getValue(const size_t& code) const
{
	if (this->code == code) {
		return this->value;
	}
	throw std::invalid_argument("The code does not match the needed code!\n");
}


template<typename T>
size_t ProtectedValue<T>::getCode() const {
	return this->code;
}

//template<typename T>
//void ProtectedValue<T>::setCode(const size_t& code) {
//	this->code = code;
//}
//
//template<typename T>
//void ProtectedValue<T>::setValue(const T& value)
//{
//	this->value = value;
//}





template<typename T>
ProtectedArray<T>::ProtectedArray() : arr(nullptr), size(0) {}

template<typename T>
ProtectedArray<T>::ProtectedArray(ProtectedValue<T>* arr, const size_t& size) {
	if (arr != nullptr) {
		delete[] this->arr;
	}
	this->size = size;
	this->arr = new ProtectedValue<T>[size];
	for (int i = 0; i < size; i++) {
		this->arr[i] = arr[i];
	}
}

template<typename T>
ProtectedArray<T>::ProtectedArray(const ProtectedArray<T>& p) {
	this->size = p.size;
	this->arr = new ProtectedValue<T>[size];
	for (int i = 0; i < size; i++) {
		this->arr[i] = p.arr[i];
	}
}

template<typename T>
ProtectedArray<T>& ProtectedArray<T>::operator=(const ProtectedArray& p) {
	if (this != &p) {
		for (int i = 0; i < this->size; i++) {
			delete[] arr;
			arr = nullptr;
			size = 0;
		}
		this->size = p.size;
		this->arr = new ProtectedValue<T>[size];

		for (int i = 0; i < p.size; i++) {
			this->arr[i] = p.arr[i];
		}
	}
	return *this;
}

template<typename T>
void ProtectedArray<T>::add(T& value, const size_t& code) {
	ProtectedValue* copy = new ProtectedValue<T>[size + 1];
	for (int i = 0; i < size; i++) {
		copy[i] = arr[i];
	}
	copy[size] = ProtectedValue<T>(value, code);
	delete[] arr;
	this->arr = copy;
	size++;
	delete[] copy;

}

template<typename T>
T ProtectedArray<T>::getValue(const size_t& code, const size_t& index) const {
	if (index < this->size) {
		return this->arr[index].getValue(code);
	}
	return T();
}

template<typename T>
void ProtectedArray<T>::setSize(const size_t& size) {
	this->size = size;
}

template<typename T>
ProtectedArray<T>::~ProtectedArray() {
	delete[] arr;
	this->size = 0;
	this->arr = nullptr;
}

