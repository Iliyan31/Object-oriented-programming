
#ifndef REQUEST
#define REQUEST
#include <iostream>
#include <string>

class Request {
protected:
	static int counter;
	std::string message;
	std::string sender;
	unsigned int ID;
public:
	Request();
	Request(const std::string& message, const std::string& sender);
	std::string getMessage() const;
	std::string getSender() const;
	int getCount() const;
	int getID() const;
};

#endif // !REQUEST