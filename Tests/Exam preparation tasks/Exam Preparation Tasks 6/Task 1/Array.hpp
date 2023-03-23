
#ifndef ARRAY
#define ARRAY
#include <cstring>
#include "Header.hpp"

template<class T>
class Array {
public:
	Array();
	Array(const Array& a);
	Array& operator=(const Array& a);
	~Array();
	void add(const T& value, const size_t& code);
	Value<T> getValueOfArray(const int& index, const size_t& value);

private:
	Value<T>* arr;
	size_t size;

	void justCopy(const Array& a);
	void justDelete();
};


template<class T>
Array<T>::Array() : arr(nullptr), size(0) {}

template<class T>
Array<T>::Array(const Array& a) {
	this->justCopy(a);
}

template<class T>
Array<T>& Array<T>::operator=(const Array& a) {
	if (this != &a) {
		this->justDelete();
		this->justCopy(a);
	}
	return *this;
}

template<class T>
Array<T>::~Array() {
	this->justDelete();
}

template<class T>
void Array<T>::add(const T& value, const size_t& code) {
	Value<T>* newArr = new Value<T>[size + 1];
	for (int i = 0; i < size; i++) {
		newArr[i] = this->arr[i];
	}
	newArr[size] = Value<T>(value, code);	
	delete[] arr;
	// this.arr = newArr
	this->arr = new Value<T>[size + 1];
	for (int i = 0; i < size +1; i++) {
		this->arr[i] = newArr[i];
	}
	this->size++;
	delete[] newArr;
}

template<class T>
Value<T> Array<T>::getValueOfArray(const int& index, const size_t& code) {
	if (index < this->size) {
		return this->arr[index].getValue(code);
	}
	else {
		printf("Error!\n");
	}
}


template<class T>
void Array<T>::justCopy(const Array& a) {
	this->size = a.size;
	this->arr = new Value<T>[size];
	for (int i = 0; i < size; i++) {
		arr[i] = a.arr[i];
	}
}

template<class T>
void Array<T>::justDelete() {
	delete[] arr;
	this->size = 0;
	this->arr = nullptr;
}


#endif // !ARRAY