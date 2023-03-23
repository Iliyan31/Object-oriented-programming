
#ifndef PERSON
#define PERSON
#include<iostream>
#include <cstring>

class Person {
public:
	Person();
	Person(const char* _name, const char* _lastname);
	Person(const Person& p);
	Person& operator=(const Person& p);
	~Person();
	
	void setName(const char* _name);
	void setLastName(const char* _lastname);

	char* getName() const;
	char* getLastName() const;

	friend std::ostream& operator<<(std::ostream& out, const Person& p);
	friend std::istream& operator>>(std::istream& in, Person& p);
private:
	char* name;
	char* lastName;
};

#endif // !PERSON