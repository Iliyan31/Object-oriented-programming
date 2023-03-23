
#ifndef FILE
#define FILE
#include<iostream>
#include <string>

class File {
public:

	File(const std::string& name = " ", const std::string& extension = " ", const size_t& size = 0);
	
	std::string getName() const;
	std::string getExtension() const;
	size_t getSize() const;

	void setName(const std::string& name);
	void setExtension(const std::string& extension);
	void setSize(const size_t& size);

	void print_debug_state() const;
	virtual File* clone() const = 0;
	virtual ~File() = default;
private:
	std::string name;
	std::string extension;
	size_t size;
};

#endif // !FILE
