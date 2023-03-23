#pragma once
#include "Special.hpp"
#include <vector>

class Player {
public:
	Player() = default;
	Player(const Player& p);
	Player& operator=(const Player& p);
	~Player();

	void addCard(Card* c);
	void removeCard(const int& index);

	void printAllcards() const;

private:
	void justCopy(const Player& p);
	void justDelete();
	std::vector<Card*> cards;
};