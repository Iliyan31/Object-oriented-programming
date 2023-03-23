#pragma once
#include <iostream>
#include <cstring>
#include <exception>

// fn: 62546
// used visual studio enterprise

template<class T>
class NamedObject {
public:
	NamedObject();
	NamedObject(const char* name, const size_t& id, const T& object);
	NamedObject(const NamedObject<T>& n);
	NamedObject<T>& operator=(const NamedObject<T>& n);
	~NamedObject();

	char* getName() const;
	size_t getID() const;
	T getObject() const;

private:
	void justCopy(const NamedObject<T>& n);
	void justClear();
	char* name;
	size_t id;
	T object;

};

template<class T>
NamedObject<T>::NamedObject() : name(nullptr), id(0), object(T())
{
}

template<class T>
NamedObject<T>::NamedObject(const char* name, const size_t& id, const T& object)
	: id(id), object(object)
{
	int size = strlen(name) + 1;
	this->name = new char[size];
	strcpy_s(this->name, size, name);
}

template<class T>
NamedObject<T>::NamedObject(const NamedObject<T>& n)
{
	 this->justCopy(n);
}

template<class T>
NamedObject<T>& NamedObject<T>::operator=(const NamedObject<T>& n)
{
	 if (this != &n) {
		 this->justClear();
		 this->justCopy(n);
	 }
	 return *this;
}

template<class T>
NamedObject<T>::~NamedObject()
{
	this->justClear();
}

template<class T>
char* NamedObject<T>::getName() const
{
	return this->name;
}

template<class T>
size_t NamedObject<T>::getID() const
{
	return this->id;
}

template<class T>
T NamedObject<T>::getObject() const
{
	return this->object;
}

template<class T>
void NamedObject<T>::justCopy(const NamedObject<T>& n)
{
	if (n.name != nullptr) {
		this->id = n.id;
		this->object = n.object;
		int size = strlen(n.name) + 1;
		this->name = new char[size];
		strcpy_s(this->name, size, n.name);
	} 
}

template<class T>
void NamedObject<T>::justClear()
{
	  delete[] this->name;
}


template<class T>
class NamedObjectArray {
public:
	NamedObjectArray();
	NamedObjectArray(const NamedObjectArray<T>& n2);
	NamedObjectArray<T>& operator=(const NamedObjectArray<T>& n2);
	~NamedObjectArray();

	void addObject(NamedObject<T>& obj);
	int getAllObjects() const;
	NamedObject<T>& operator[](const int& index) const;

private:
	void justCopy2(const NamedObjectArray<T>& n2);
	void justClear2();
	void resize();
	int size;
	int capacity;
	NamedObject<T>* container;
};

template<class T>
NamedObjectArray<T>::NamedObjectArray() : container(nullptr), size(0), capacity(1)
{
}

template<class T>
NamedObjectArray<T>::NamedObjectArray(const NamedObjectArray<T>& n2)
{
	this->justCopy2(n2);
}

template<class T>
NamedObjectArray<T>& NamedObjectArray<T>::operator=(const NamedObjectArray<T>& n2)
{
	if (this != &n2) {
		this->justClear2();
		this->justCopy2(n2);
	}
	return *this;
}

template<class T>
NamedObjectArray<T>::~NamedObjectArray()
{
	this->justClear2();
}

template<class T>
void NamedObjectArray<T>::addObject(NamedObject<T>& obj)
{
	if (this->size == this->capacity) {
		this->resize();
	}
	else {
		this->container[size] = obj;
		this->size++;
	}
}

template<class T>
int NamedObjectArray<T>::getAllObjects() const {
	return this->size;
}

template<class T>
NamedObject<T>& NamedObjectArray<T>::operator[](const int& index) const {
	if (index < this->size) {
		
	}
	else {
		return this->container[index];
			throw std::out_of_range("Out of range!\n");
	}
}

template<class T>
void NamedObjectArray<T>::justCopy2(const NamedObjectArray<T>& n2)
{
	if (n2 != nullptr) {
		this->capacity = n2.capacity;
		this->size = n2.size;
		this->container = new NamedObject<T>[capacity];
		for (int i = 0; i < size; i++) {
			this->container[i] = n2.container[i];
		}
	}
}

template<class T>
void NamedObjectArray<T>::justClear2()
{
	delete[] this->container;
}

template<class T>
void NamedObjectArray<T>::resize()
{
	this->capacity *= 2;
	NamedObject<T>* newContainer = new NamedObject<T>[capacity];
	for (int i = 0; i < size; i++) {
		newContainer[i] = this->container[i];
	}
	this->justClear2();
	this->container = new NamedObject<T>[capacity];
	for (int i = 0; i < size; i++) {
		this->container[i] = newContainer[i];
	}
}
