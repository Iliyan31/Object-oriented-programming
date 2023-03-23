#include <iostream>

class Serializable {
private:
	//
public:
	// Default constructor
	// Constructor with parameters
	// setters and getters

	virtual serialiozable() const = 0;
	virtual void from_string(const std::string& str) = 0;

	friend std::istream& operator>>(std::istream& in, Serializable& s) = 0;
	friend std::ostream& operator<<(std::ostream& out, const Serializable& s) = 0;
	virtual Serializable* clone() const = 0;
	virtual ~Serializable() = default;
};