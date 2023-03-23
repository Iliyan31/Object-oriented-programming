
#ifndef CARD
#define CARD
#include <iostream>
#include <string>

enum class Type {
	hero,
	magic,
	special,
	none
};

class Card {
public:
	Card(const std::string& name = " ", const size_t& size = 0, const size_t& number = 0, Type type = Type::none);

	void setName(const std::string& name);
	void setSize(const size_t& size);
	void setNumber(const size_t& number);

	std::string getName() const;
	size_t getSize() const;
	size_t getNumber() const;

	virtual void printCards() const = 0;
	virtual Card* clone() const = 0;
	virtual ~Card() = default;

private:
	Type type;
	std::string name;
	size_t size;
	size_t number;
};

#endif // !CARD