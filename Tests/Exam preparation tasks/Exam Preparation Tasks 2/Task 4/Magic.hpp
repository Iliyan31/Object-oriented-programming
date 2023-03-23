
#ifndef MAGIC
#define MAGIC
#include "Card.hpp"

class Magic : virtual public Card {
public:
	Magic(const std::string& name = " ", const size_t& size = 0, const size_t& number = 0, const std::string& effect = " ");

	void setEffect(const std::string& name);
	std::string getEffect() const;

	Card* clone() const;
	~Magic() = default;

	void printCards() const;
private:
	std::string effect;
};

#endif // !MAGIC