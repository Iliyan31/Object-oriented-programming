
#include "Player.hpp"

Player::Player(const Player& p)
{
	this->justCopy(p);
}

Player& Player::operator=(const Player& p) {
	if (this != &p) {
		this->justDelete();
		this->justCopy(p);
	}
	return *this;
}

Player::~Player() {
	this->justDelete();
}

void Player::addCard(Card* c) {
	this->cards.push_back(c->clone());
}

void Player::removeCard(const int& index) {
	if (index < this->cards.size()) {
		this->cards.erase(this->cards.begin() + index);
	}
}

void Player::printAllcards() const {
	for (int i = 0; i < this->cards.size(); i++) {
		Hero* hero = dynamic_cast<Hero*>(this->cards[i]);
		Magic* magic = dynamic_cast<Magic*>(this->cards[i]);
		Special* special = dynamic_cast<Special*>(this->cards[i]);
		if (hero && !special) {
			hero->printCards();
		}
		if (magic && !special) {
			magic->printCards();
		}
		if (special && !hero && !magic) {
			special->printCards();
		}
	}
}

void Player::justCopy(const Player& p) {
	this->cards.clear();
	for (int i = 0; i < p.cards.size(); i++) {
		this->addCard(p.cards[i]);
	}
}

void Player::justDelete() {
	for (int i = 0; i < cards.size(); i++) {
		delete this->cards[i];
	}
}
