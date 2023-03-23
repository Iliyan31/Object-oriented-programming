
#ifndef SPECIAL
#define SPECIAL
#include "Hero.hpp"
#include "Magic.hpp"

class Special : public Hero, public Magic {
public:
	Special(const std::string& name = " ", const size_t& size = 0, const size_t& number = 0,
		const size_t attack = 0, const size_t protect = 0, const std::string& effect = " ", const size_t& level = 0);

	void setLevel(const size_t& level);
	size_t getLevel() const;

	Card* clone() const;
	~Special() = default;
	void printCards() const;
private:
	size_t level;
};


#endif // !SPECIAL
