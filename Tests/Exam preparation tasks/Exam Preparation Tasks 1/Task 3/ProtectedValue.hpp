#pragma once
#include <exception>
#include<iostream>

template<class T>
class ProtectedValue {
public:
	ProtectedValue();
	ProtectedValue(const T& value, const size_t& code);

	size_t getCode() const;
	T getValue(const size_t& code) const;
	void changeCode(const size_t& code);

private:
	size_t code;
	T value;

};

template<class T>
ProtectedValue<T>::ProtectedValue() : value(T()), code(0)
{
}

template<class T>
ProtectedValue<T>::ProtectedValue(const T& value, const size_t& code) : value(value), code(code) {
}

template<class T>
size_t ProtectedValue<T>::getCode() const
{
	 return this->code;
}

template<class T>
T ProtectedValue<T>::getValue(const size_t& code) const
{
	 if (this->code == code) {
		 return this->value;
	 }
}

template<class T>
void ProtectedValue<T>::changeCode(const size_t& code)
{
	this->code = code;
}




template <class T> 
class ProtectedArray {
public:
	ProtectedArray();
	ProtectedArray(const ProtectedArray<T>& from);
	ProtectedArray<T>& operator=(const ProtectedArray<T>& from);
	~ProtectedArray();

	void AddElement(const T& element, const size_t& code);
	void getElement(const int& index, const size_t& code);

private:
	void resize();
	void justCopy(const ProtectedArray<T>& from);
	void justClear();

	ProtectedValue<T>* array;
	size_t size;
	size_t capacity
};

template<class T>
ProtectedArray<T>::ProtectedArray() : size(1), capacity(1) 
{
	this->array = new ProtectedValue<T>[capacity];
	this->array[0] = T();
}

template<class T>
 ProtectedArray<T>::ProtectedArray(const ProtectedArray<T>& from)
{
	 this->justCopy(from);
}

template<class T>
 ProtectedArray<T>& ProtectedArray<T>::operator=(const ProtectedArray<T>& from) {
	 if (this != &from) {
		 this->justClear();
		 this->justCopy(from);
	 }
	 return *this;
}

template<class T>
 ProtectedArray<T>::~ProtectedArray()
{
	 this->justClear();
}

 template<class T>
 void ProtectedArray<T>::AddElement(const T& element, const size_t& code)
 {
	 if (this->size == capacity) {

	 }
	 ProtectedValue<T>* newArr = new ProtectedValue<T>[];

 }

 template<class T>
 void ProtectedArray<T>::getElement(const int& index, const size_t& code)
 {
	 
 }

 template<class T>
 void ProtectedArray<T>::resize()
 {
	 this->capacity *= 2;
	 ProtectedValue<T>* newArr = new ProtectedValue<T>[capacity];
	 for (int i = 0; i < this->size; i++) {
		 newArr[i] = this->array[i];
	 }
	 this->justClear();
	 this->array = new  ProtectedValue<T>[capacity];
	 for (int i = 0; i < this->size; i++) {
		 this->array[i] = newArr[i];
	 }
 }

 template<class T>
 void ProtectedArray<T>::justCopy(const ProtectedArray<T>& from)
{
	 this->capacity = from.capacity;
	 this->size = from.size;
	 this->array = new ProtectedValue<T>[capacity];
	 for (int i = 0; i < this->size; i++) {
		 this->array[i] = from.array[i];
	 }
}

template<class T>
 void ProtectedArray<T>::justClear()
{
	 delete[] this->array;
}
