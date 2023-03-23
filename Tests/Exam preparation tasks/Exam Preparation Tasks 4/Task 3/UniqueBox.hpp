#pragma once
#include <iostream>

template<class T>
class UniqueBox {
public:
	UniqueBox();
	UniqueBox(const UniqueBox& from);
	UniqueBox& operator=(const UniqueBox& from);
	~UniqueBox();

	void operator+=(const T& element);
	T& operator[](const int& index);					// const?
	int get_counter() const;
private:
	void justCopy(const UniqueBox& from);
	void justClear();
	void resize();
	T* container;
	int size;
	int capacity;
};

template<class T>
UniqueBox<T>::UniqueBox() : size(0), capacity(1) {
	this->container = new T[1];
}

template<class T>
UniqueBox<T>::UniqueBox(const UniqueBox& from) {
	this->justCopy(from);
}

template<class T>
UniqueBox<T>& UniqueBox<T>::operator=(const UniqueBox<T>& from) {
	if (this != &from) {
		this->justClear();
		this->justCopy(from);
	}
	return *this;
}

template<class T>
UniqueBox<T>::~UniqueBox()
{
	this->justClear();
}

template<class T>
void UniqueBox<T>::operator+=(const T& element) {
	bool flag = false;
	if (this->size == this->capacity) {
		this->resize();
	}
	for (int i = 0; i <size; i++) {
		if (this->container[i] == element) {
			flag == true;
		}
	}
	if (flag == false) {
		this->container[size] = element;
		this->size++;
	}
	else {
		printf("The element exists!\n");
	}
}

template<class T>
T& UniqueBox<T>::operator[](const int& index) {
	return this->container[index];
}

template<class T>
int UniqueBox<T>::get_counter() const {
	return this->size;
}

template<class T>
void UniqueBox<T>::justCopy(const UniqueBox<T>& from) {

	this->capacity = from.capacity;
	this->size = from.size;

	this->container = new T[this->capacity];
	for (int i = 0; i < this->size; i++) {
		this->container[i] = from.container[i];
	}
}

template<class T>
void UniqueBox<T>::justClear()
{
	delete[] this->container;
}

template<class T>
void UniqueBox<T>::resize()
{
	T* newArr = new T[capacity * 2];
	for (int i = 0; i < this->size; i++) {
		newArr[i] = this->container[i];
	}
	this->justClear();
	this->capacity *= 2;
	this->container = newArr;
}
