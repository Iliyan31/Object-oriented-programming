
#ifndef HEADER
#define HEADER
	

#include <iostream>
#include <cstring>

class ToDo {
private:
	char* Id;
	bool finished;
public:
	ToDo(const char* = "111", bool = false);
	ToDo(const ToDo& t);
	ToDo& operator=(const ToDo& t);
	~ToDo();
	void print() const;
};

#endif // !HEADER